/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/Foundation.h>
#import <AirKit/AirKitExport.h>
#import <ApplicationServices/ApplicationServices.h>

@class NSColor;

typedef enum {
   NSCompositeClear,
   NSCompositeCopy,
   NSCompositeSourceOver,
   NSCompositeSourceIn,
   NSCompositeSourceOut,
   NSCompositeSourceAtop,
   NSCompositeDestinationOver,
   NSCompositeDestinationIn,
   NSCompositeDestinationOut,
   NSCompositeDestinationAtop,
   NSCompositeXOR,
   NSCompositePlusDarker,
   NSCompositeHighlight,
   NSCompositePlusLighter
} NSCompositingOperation;

typedef enum {
   NSWindowBelow=-1,
   NSWindowOut=0,
   NSWindowAbove=1
} NSWindowOrderingMode;

typedef enum {
   NSFocusRingOnly,
   NSFocusRingBelow,
   NSFocusRingAbove
} NSFocusRingPlacement;

typedef enum {
   NSFocusRingTypeDefault,
   NSFocusRingTypeNone,
   NSFocusRingTypeExterior
} NSFocusRingType;

typedef int NSWindowDepth;

enum {
   NSAnimationEffectDisappearingItemDefault= 0,
   NSAnimationEffectPoof                   =10,
};
typedef NSUInteger NSAnimationEffect;

AirKit_EXPORT const float NSBlack;
AirKit_EXPORT const float NSDarkGray;
AirKit_EXPORT const float NSLightGray;
AirKit_EXPORT const float NSWhite;

AirKit_EXPORT NSString * const NSDeviceBlackColorSpace;
AirKit_EXPORT NSString * const NSDeviceWhiteColorSpace;
AirKit_EXPORT NSString * const NSDeviceRGBColorSpace;
AirKit_EXPORT NSString * const NSDeviceCMYKColorSpace;
AirKit_EXPORT NSString * const NSCalibratedBlackColorSpace;
AirKit_EXPORT NSString * const NSCalibratedWhiteColorSpace;
AirKit_EXPORT NSString * const NSCalibratedRGBColorSpace;
AirKit_EXPORT NSString * const NSNamedColorSpace;
AirKit_EXPORT NSString * const NSPatternColorSpace;

AirKit_EXPORT NSString * const NSDeviceIsScreen;
AirKit_EXPORT NSString * const NSDeviceIsPrinter;
AirKit_EXPORT NSString * const NSDeviceSize;
AirKit_EXPORT NSString * const NSDeviceResolution;
AirKit_EXPORT NSString * const NSDeviceColorSpaceName;
AirKit_EXPORT NSString * const NSDeviceBitsPerSample;

AirKit_EXPORT void NSRectClipList(const NSRect *rects,int count);
AirKit_EXPORT void NSRectClip(NSRect rect);

AirKit_EXPORT void NSRectFillListWithColors(const NSRect *rects,NSColor **colors,int count);
AirKit_EXPORT void NSRectFillListWithGrays(const NSRect *rects,const float *grays,int count);
AirKit_EXPORT void NSRectFillList(const NSRect *rects,int count);
AirKit_EXPORT void NSRectFill(NSRect rect);

AirKit_EXPORT void NSRectFillListUsingOperation(const NSRect *rects,int count,NSCompositingOperation operation);
AirKit_EXPORT void NSRectFillUsingOperation(NSRect rect,NSCompositingOperation operation);

AirKit_EXPORT void NSFrameRectWithWidth(NSRect rect,CGFloat width);
AirKit_EXPORT void NSFrameRectWithWidthUsingOperation(NSRect rect,CGFloat width,NSCompositingOperation operation);
AirKit_EXPORT void NSFrameRect(NSRect rect);
AirKit_EXPORT void NSDottedFrameRect(NSRect rect);

AirKit_EXPORT void NSDrawButton(NSRect rect,NSRect clipRect);
AirKit_EXPORT void NSDrawGrayBezel(NSRect rect,NSRect clipRect);
AirKit_EXPORT void NSDrawWhiteBezel(NSRect rect,NSRect clipRect);
AirKit_EXPORT void NSDrawDarkBezel(NSRect rect,NSRect clipRect);
AirKit_EXPORT void NSDrawLightBezel(NSRect rect,NSRect clipRect);
AirKit_EXPORT void NSDrawGroove(NSRect rect,NSRect clipRect);

AirKit_EXPORT void NSDrawWindowBackground(NSRect rect);

AirKit_EXPORT NSRect NSDrawTiledRects(NSRect bounds,NSRect clip,const NSRectEdge *sides,const float *grays,int count);

AirKit_EXPORT void NSHighlightRect(NSRect rect);
AirKit_EXPORT void NSCopyBits(int gState,NSRect rect,NSPoint point);

AirKit_EXPORT void NSBeep();

AirKit_EXPORT void NSEnableScreenUpdates(void);
AirKit_EXPORT void NSDisableScreenUpdates(void);

AirKit_EXPORT void NSShowAnimationEffect(NSAnimationEffect effect,NSPoint center,NSSize size,id delegate,SEL didEndSelector,void *context);
