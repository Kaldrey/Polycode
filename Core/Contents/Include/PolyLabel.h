/*
 *  PolyLabel.h
 *  TAU
 *
 *  Created by Ivan Safrin on 3/16/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
// @package BasicTypes
 
#pragma once

#include "PolyGlobals.h"
#include "PolyFont.h"
#include "PolyImage.h"
#include "PolyUtil.h"

#include <string>
using namespace std;

using std::wstring;

#define TAB_REPLACE "    "

namespace Polycode {

	class _PolyExport Label : public Image {
		public:
			
			Label(Font *font, wstring text, int size, int antiAliasMode);
			~Label();
			void setText(wstring text);
			wstring getText();
			int getTextWidth(Font *font, wstring text, int size);
			int getTextHeight(Font *font, wstring text, int size);
					
			float getTextWidth();		
			float getTextHeight();
		
			Font *getFont();
					
			static const int ANTIALIAS_FULL = 0;
			static const int ANTIALIAS_NONE = 1;
			
		private:

			float currentTextWidth;
			float currentTextHeight;
			int antiAliasMode;
			int size;
			wstring text;
			Font *font;
	};

}