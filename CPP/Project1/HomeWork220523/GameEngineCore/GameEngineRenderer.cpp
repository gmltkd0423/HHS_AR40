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

	//����
	float4 Dir = float4::DegreeToDirection2D(Angle);

	//���� �Ÿ�
	Dis += 2.0f * _DeltaTime;
	//���� �ӵ�
	RotZ += 1000.0f * _DeltaTime;

	//���� �ӵ�
	Angle += 360.0f * _DeltaTime;
	//����
	GetActor()->GetTransform().SetPosition(float4{ 300.0f,300.0f } + Dir * Dis);
	
	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		int TriIndex = Index->Indexs[i];

		// 0 ��° ������ ���� �˴ϴ�.
		CopyBuffer[i] = Vertex->Vertexs[TriIndex];

		// [0.5f] [0.5f] []                  [100] [100] [] 
		// ũ
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();

		// ����
		//CopyBuffer[TriIndex] *= GetActor()->GetTransform().GetScale();

		// �̵�
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();

		

		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}

	//����
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