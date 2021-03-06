/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <AirKit/NSText.h>

typedef enum {
   NSLineBreakByWordWrapping,
   NSLineBreakByCharWrapping,
   NSLineBreakByClipping,
   NSLineBreakByTruncatingHead,
   NSLineBreakByTruncatingTail,
   NSLineBreakByTruncatingMiddle
} NSLineBreakMode;

@interface NSParagraphStyle : NSObject <NSCopying,NSMutableCopying> {
   NSWritingDirection _writingDirection;
   float              _paragraphSpacing;
   float              _paragraphSpacingBefore;
   NSArray           *_textBlocks;
   NSArray           *_textLists;
   int                _headerLevel;
   float              _firstLineHeadIndent;
   float              _headIndent;
   float              _tailIndent;
   NSTextAlignment    _alignment;
   NSLineBreakMode    _lineBreakMode;
   float              _minimumLineHeight;
   float              _maximumLineHeight;
   float              _lineHeightMultiple;
   float              _lineSpacing;
   float             _defaultTabInterval;
   NSArray          *_tabStops;
   float             _hyphenationFactor;
   float             _tighteningFactorForTruncation;
}

+(NSParagraphStyle *)defaultParagraphStyle;

-(NSWritingDirection)baseWritingDirection;

-(float)paragraphSpacing;
-(float)paragraphSpacingBefore;

-(NSArray *)textBlocks;
-(NSArray *)textLists;

-(int)headerLevel;

-(float)firstLineHeadIndent;
-(float)headIndent;
-(float)tailIndent;

-(NSTextAlignment)alignment;
-(NSLineBreakMode)lineBreakMode;

-(float)minimumLineHeight;
-(float)maximumLineHeight;
-(float)lineHeightMultiple;
-(float)lineSpacing;

-(float)defaultTabInterval;
-(NSArray *)tabStops;

-(float)hyphenationFactor;
-(float)tighteningFactorForTruncation;

@end

#import <AirKit/NSMutableParagraphStyle.h>
