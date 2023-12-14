#include "TextRender.h"

void TextRender::Tick()
{
	textObj.Render(&gameObject->transform);
}

void TextRender::SetText(std::string text)
{
	if (text == currentText) return;

	textObj.SetText(text, r, g, b);

	currentText = text;
}