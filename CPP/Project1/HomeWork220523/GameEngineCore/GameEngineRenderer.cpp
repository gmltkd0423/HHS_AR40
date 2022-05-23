#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

GameEngineRenderer::GameEngineRenderer() 
{
}

GameEngineRenderer::~GameEngineRenderer() 
{
}


void GameEngineRenderer::Start() 
{
	GetActor()->GetLevel()->PushRenderer(this);
}

float Angle = 0.0f;
float Dis = 0.0f;
float RotZ = 0.0f;

void GameEngineRenderer::Render(float _DeltaTime)
{
	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("Rect");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("Rect");
	
	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());

	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());

	//공전
	float4 Dir = float4::DegreeToDirection2D(Angle);

	//공전 거리
	Dis += 2.0f * _DeltaTime;
	//자전 속도
	RotZ += 1000.0f * _DeltaTime;

	//공전 속도
	Angle += 360.0f * _DeltaTime;
	//공전
	GetActor()->GetTransform().SetPosition(float4{ 300.0f,300.0f } + Dir * Dis);
	
	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		int TriIndex = Index->Indexs[i];

		// 0 번째 순서의 점이 됩니다.
		CopyBuffer[i] = Vertex->Vertexs[TriIndex];

		// [0.5f] [0.5f] []                  [100] [100] [] 
		// 크
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();

		// 자전
		//CopyBuffer[TriIndex] *= GetActor()->GetTransform().GetScale();

		// 이동
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();

		

		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}

	//자전
	for (size_t i = 0; i < DrawVertex.size(); i ++)
	{
		Vertex->Vertexs[i] = float4::VectorRotationToRadianZ(Vertex->Vertexs[i], 1.0f*_DeltaTime);
	}
	
	for (size_t i = 0; i < DrawVertex.size(); i += 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}
	

	// Rectangle(GameEngineWindow::GetHDC(), LeftTop.ix(), LeftTop.iy(), RightBot.ix(), RightBot.iy());
}