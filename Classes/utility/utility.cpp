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
	int row = ceil(text->getVirtualRendererSize().width / text->getSize().width);//����
	
	int width_text = text->getVirtualRendererSize().width;//�ܹ��ı����

	int width_content = text->getSize().width;

	std::string str = text->getStringValue();//�ı�����

	float avi_width = width_text / str.length();//ÿ���ַ��Ŀ��
	
	int num_row = width_content / avi_width;//ÿ�ж����ַ�
	CCLOG("%d", num_row);
	
	std::string new_str = "";
	//ÿ�м��ϻ��з�
	int i = 0, count = 0;//��i���ַ������е�count���ַ�
	while (i<str.length())
	{
		if (str[i] < 0)
		{//Ϊ����
			new_str += str[i];
			new_str += str[++i];
			count += 2;
		}else
		{//Ϊansci
			new_str += str[i];
			count += 1;
		}
		++i;
		if (count >= num_row)
		{//����
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



void utility::setEnable(bool flag, Layer* layer)//�����¼�
{
	layer->setTouchEnabled(flag);
	layer->setKeyboardEnabled(flag);
}