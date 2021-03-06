#include "Figure.h"

std::vector<std::vector<Point>> Generate()// �������� ������
{
	switch (rand() % 7) // ������ 7 �����
	{
	case 0: return
	{
		{ Point(0, 0), Point(1, 0), Point(2, 0), Point(3, 0) },//����� ___
		{ Point(1, 0), Point(1, 1), Point(1, 2), Point(1, 3) } // |
	};

	case 1: return // � � ������ �������
	{ 
		{Point(0, 0), Point(1, 0), Point(1, 1), Point(1, 2)}, // `|
		{Point(0, 1), Point(1, 1), Point(2, 1), Point(2, 0)}, // _ _|
		{Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 2)}, // L
		{Point(0, 0), Point(1, 0), Point(2, 0), Point(0, 1)}  // |```
	};

	case 2: return // �
	{
		{Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 0)}, // �
		{Point(0, 0), Point(1, 0), Point(2, 0), Point(2, 1)}, // ```|
		{Point(1, 0), Point(1, 1), Point(1, 2), Point(0, 2)}, // _|
		{Point(0, 1), Point(1, 1), Point(2, 1), Point(0, 0)}  // |_ _
	};

	case 3: return
	{
		{ Point(0, 0), Point(1, 0), Point(2, 0), Point(1, 1) },// |-
		{ Point(1, 0), Point(1, 1), Point(1, 2), Point(0, 1) },// _|_
		{ Point(0, 1), Point(1, 1), Point(2, 1), Point(1, 0) },// -|
		{ Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 1) } // `T`
	};

	case 4: return
	{
		{Point(0, 0), Point(1, 0), Point(1, 1), Point(2, 1)}, // z
		{Point(1, 0), Point(1, 1), Point(0, 1), Point(0, 2)}  // N
	};

	case 5: return //z � ������ �������
	{
		{Point(2, 0), Point(1, 0), Point(1, 1), Point(0, 1)}, // _|`
		{Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 2)}  // �
	};

	case 6: return 
	{
		{Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0)}, //�������
	};
	default:
		break;
	}
}

Figure::Figure(Point position)// ����������� ���������� ������ � position
{
	m_Position = position;
	m_Body = Generate();
}

void Figure::Update(double dt) // ������� ������ ����
{
	m_TimeFromLastUpdate += dt;
	if (m_TimeFromLastUpdate <= m_TimeForUpdate) return;
	m_TimeFromLastUpdate = 0;

	++m_Position.y;
}

void Figure::Draw(Canvas& canvas) 
{
	for (const Point& point : m_Body[m_CurrentRotate]) {
		canvas.SetChar(point.x + m_Position.x, point.y + m_Position.y, 0x25D8);
	}
}

void Figure::MoveR() 
{
	++m_Position.x;
}

void Figure::MoveL() 
{
	m_Position.x--;
}

void Figure::Rotate()// ������� ������
{
	++m_CurrentRotate;
	if (m_CurrentRotate >= m_Body.size()) { //����� ���������� �������� ��������� � ��������� �����
		m_CurrentRotate = 0;
	}
}

const std::vector<Point>& Figure::GetBody() const
{
	return m_Body[m_CurrentRotate];
}

Point Figure::GetPosition()const 
{
	return m_Position;
}

void Figure::SetPosition(Point position)
{
	m_Position = position;
}

void Figure::BackUp()// ���������� ��������� ������
{
	m_PositionBackUp = m_Position;
	m_CurrentRotateBackUp = m_CurrentRotate;
}

void Figure::Restore() //��������� � ���������� ���������
{
	m_Position = m_PositionBackUp;
	m_CurrentRotate = m_CurrentRotateBackUp;
}

void Figure::Boost()// ������� ��������� ������
{
	m_TimeForUpdate = 50;
}

/*std::vector<std::vector<Point>> Generate()
{
	return std::vector<std::vector<Point>>();
}
*/