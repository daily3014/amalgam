#include "Fonts.h"

void CFonts::Reload(float flDPI)
{
	m_mapFonts[FONT_ESP]		= { "micross",		12,			FONTFLAG_DROPSHADOW,	600 }; // for player names
	m_mapFonts[FONT_ESP_SMALL]	= { "Small Fonts",	8,			FONTFLAG_DROPSHADOW,	0 }; // flags
	m_mapFonts[FONT_ESP_MEDIUM] = { "Small Fonts",	5*2,		FONTFLAG_DROPSHADOW,	0 }; // weapon name
	m_mapFonts[FONT_INDICATORS] = { "micross",		13,			FONTFLAG_OUTLINE,		0 }; // visual indicators

	for (auto& [_, fFont] : m_mapFonts)
	{
		I::MatSystemSurface->SetFontGlyphSet
		(
			fFont.m_dwFont = I::MatSystemSurface->CreateFont(),
			fFont.m_szName,		//name
			fFont.m_nTall,		//tall
			fFont.m_nWeight,	//weight
			0,					//blur
			0,					//scanlines
			fFont.m_nFlags		//flags
		);
	}
}

const Font_t& CFonts::GetFont(EFonts eFont)
{
	return m_mapFonts[eFont];
}