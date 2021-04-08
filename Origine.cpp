#include<windows.h>
#include<iostream>
void MouseMove(float x, float y)
{
	double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	::SendInput(1, &Input, sizeof(INPUT));
}

int main() {
	while (true)
	{
		POINT Mouse_Pos;
		GetCursorPos(&Mouse_Pos);
		float randx, randy;
		randx = (2 * (float)rand()/RAND_MAX) - 1;
		randy = (2 * (float)rand()/RAND_MAX) - 1;
		std::cout << randx << "  " << randy << "\n";
		MouseMove(Mouse_Pos.x + randx, Mouse_Pos.y + randy);
		Sleep(3000);
	}

}