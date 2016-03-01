#include "utility.h"



utility::~utility()
{
}

bool utility::isStringLegal(std::string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if ((str[i] >= '0'&&str[i] <= '9')
			|| (str[i] >= 'A'&&str[i] <= 'Z')
			|| (str[i] >= 'a'&&str[i] <= 'z')
			|| str[i] == '.'
			|| str[i] == '@')
		{}else
		{
			return false;
		}
	}
	return str.length() >= 6;
}

void utility::setTextAuto(Text* text)
{
	int row = ceil(text->getVirtualRendererSize().width / text->getSize().width);//行数
	
	int width_text = text->getVirtualRendererSize().width;//总共文本宽度

	int width_content = text->getSize().width;

	std::string str = text->getStringValue();//文本内容

	float avi_width = width_text / str.length();//每个字符的宽度
	
	int num_row = width_content / avi_width;//每行多少字符
	CCLOG("%d", num_row);
	
	std::string new_str = "";
	//每行加上换行符
	int i = 0, count = 0;//第i个字符，该行第count个字符
	while (i<str.length())
	{
		if (str[i] < 0)
		{//为中文
			new_str += str[i];
			new_str += str[++i];
			count += 2;
		}else
		{//为ansci
			new_str += str[i];
			count += 1;
		}
		++i;
		if (count >= num_row)
		{//换行
			new_str += "\n";
			count = 0;
		}
	}

	text->setText(new_str);
}

bool utility::isNameLegal(std::string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '\''
			|| str[i] == '\"'
			|| str[i] == '<'
			|| str[i] == '>'
			|| str[i] == '\\'
			|| str[i] == ' ')
		{
			return false;
		}
	}
	return str.length() > 0;
}



void utility::setEnable(bool flag, Layer* layer)//屏蔽事件
{
	layer->setTouchEnabled(flag);
	layer->setKeyboardEnabled(flag);
}