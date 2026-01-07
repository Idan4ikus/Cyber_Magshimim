#include "Controller.h"

Controller::Controller()
{
	//std::string bb = ;
	this->bd = new Board();
}

std::string Controller::menageMove(std::string cords)
{
	std::string FromCord = cords.substr(0, 2);
	std::string ToCord = cords.substr(2, 2);
	int res = bd->isLegalMove(FromCord , ToCord);
	if (res == 0 || res == 1)
		bd->UpdateBoard(FromCord , ToCord);

	std::string resStr = "";

	resStr += (res + '0');
	resStr += '\0';

	return convert(resStr);
}

std::string Controller::convert(std::string meidan)
{
	std::string res = "a";

	res[0] = meidan[0];
	res[1] = '\0';


	return res;
}
