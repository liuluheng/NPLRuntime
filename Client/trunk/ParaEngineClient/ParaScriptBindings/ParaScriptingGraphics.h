#pragma once

namespace ParaEngine
{
	struct GUIFontElement;
	struct GUITextureElement;
}

namespace ParaScripting
{
	using namespace ParaEngine;

	/**
	* @ingroup ParaUI
	* a GUI texture object
	@par Class Properties
	- ("transparency",&ParaUITexture::GetTransparency,&ParaUITexture::SetTransparency)
	- ("color",&ParaUITexture::GetColor,&ParaUITexture::SetColor)
	- ("texture",&ParaUITexture::GetTexture,&ParaUITexture::SetTexture)
	- ("rect",&ParaUITexture::GetTextureRect,&ParaUITexture::SetTextureRect),
	*/
	class PE_CORE_DECL ParaUITexture {
	protected:
		GUITextureElement* m_pObj;
	public:
		/**
		* check if the object is valid
		*/
		bool IsValid(){ return m_pObj != NULL; }
		ParaUITexture(GUITextureElement* obj){ m_pObj = obj; };
		DWORD GetTransparency()const;
		void SetTransparency(DWORD transparency);
		std::string GetColor()const;
		void SetColor(const char *strColor);
		std::string GetTexture()const;
		void SetTexture(const char *texturename);
		std::string GetTextureRect()const;
		void SetTextureRect(const char *strrect);
	};

	/**
	* @ingroup ParaUI
	* a GUI font object
	@par Class Properties
	- ("transparency",&ParaUIFont::GetTransparency,&ParaUIFont::SetTransparency)
	- ("color",&ParaUIFont::GetColor,&ParaUIFont::SetColor)
	- ("font",&ParaUIFont::GetFont,&ParaUIFont::SetFont)
	- ("format",&ParaUIFont::GetFormat,&ParaUIFont::SetFormat),
	*/
	class PE_CORE_DECL ParaUIFont {
	protected:
		GUIFontElement* m_pObj;
	public:
		ParaUIFont(GUIFontElement* obj){ m_pObj = obj; };

		/**
		* check if the object is valid
		*/
		bool IsValid(){ return m_pObj != NULL; }


		DWORD GetTransparency()const;
		void SetTransparency(DWORD transparency);
		std::string GetColor()const;
		void SetColor(const char *strColor);
		DWORD GetFormat()const;

		/**
		Set the text align and other text displaying formats
		@param dwFormat: the new format. It can be any combination of the following values.
		DT_BOTTOM (0x00000008)
		Justifies the text to the bottom of the rectangle. This value must be combined with DT_SINGLELINE.
		DT_CALCRECT (0x00000400)
		Determines the width and height of the rectangle. If there are multiple lines of text, ID3DXFont::DrawText uses the width of the rectangle pointed to by the pRect parameter and extends the base of the rectangle to bound the last line of text. If there is only one line of text, ID3DXFont::DrawText modifies the right side of the rectangle so that it bounds the last character in the line. In either case, ID3DXFont::DrawText returns the height of the formatted text but does not draw the text.
		DT_CENTER (0x00000001)
		Centers text horizontally in the rectangle.
		DT_EXPANDTABS (0x00000040)
		Expands tab characters. The default number of characters per tab is eight.
		DT_LEFT (0x00000000)
		Aligns text to the left.
		DT_NOCLIP (0x00000100)
		Draws without clipping. ID3DXFont::DrawText is somewhat faster when DT_NOCLIP is used.
		DT_RIGHT (0x00000002)
		Aligns text to the right.
		DT_RTLREADING
		Displays text in right-to-left reading order for bi-directional text when a Hebrew or Arabic font is selected. The default reading order for all text is left-to-right.
		DT_SINGLELINE (0x00000020)
		Displays text on a single line only. Carriage returns and line feeds do not break the line.
		DT_TOP (0x00000000)
		Top-justifies text.
		DT_VCENTER (0x00000004)
		Centers text vertically (single line only).
		DT_WORDBREAK (0x00000010)
		Breaks words. Lines are automatically broken between words if a word would extend past the edge of the rectangle specified by the pRect parameter. A carriage return/line feed sequence also breaks the line.
		*/
		void SetFormat(DWORD format);
		std::string GetFont()const;
		void SetFont(const char *fontname);
	};
}