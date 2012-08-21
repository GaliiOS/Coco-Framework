/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>
#import <Foundation/NSGeometry.h>
#import <AirKit/AirKitExport.h>

@class NSDictionary,NSMutableDictionary,NSPrinter;

typedef int NSPrintingPaginationMode;

typedef enum {
   NSPortraitOrientation,
   NSLandscapeOrientation,
} NSPrintingOrientation;

AirKit_EXPORT NSString * const NSPrintPrinter;	
AirKit_EXPORT NSString * const NSPrintPrinterName; 
AirKit_EXPORT NSString * const NSPrintJobDisposition; 
AirKit_EXPORT NSString * const NSPrintDetailedErrorReporting; 

AirKit_EXPORT NSString * const NSPrintSpoolJob;
AirKit_EXPORT NSString * const NSPrintPreviewJob;
AirKit_EXPORT NSString * const NSPrintSaveJob;
AirKit_EXPORT NSString * const NSPrintCancelJob;

AirKit_EXPORT NSString * const NSPrintSavePath;

AirKit_EXPORT NSString * const NSPrintCopies; 
AirKit_EXPORT NSString * const NSPrintAllPages; 
AirKit_EXPORT NSString * const NSPrintFirstPage; 
AirKit_EXPORT NSString * const NSPrintLastPage; 

AirKit_EXPORT NSString * const NSPrintPaperName; 
AirKit_EXPORT NSString * const NSPrintPaperSize; 
AirKit_EXPORT NSString * const NSPrintOrientation; 

AirKit_EXPORT NSString * const NSPrintHorizontalPagination; 
AirKit_EXPORT NSString * const NSPrintVerticalPagination; 

AirKit_EXPORT NSString * const NSPrintTopMargin; 
AirKit_EXPORT NSString * const NSPrintBottomMargin; 
AirKit_EXPORT NSString * const NSPrintLeftMargin; 
AirKit_EXPORT NSString * const NSPrintRightMargin; 
AirKit_EXPORT NSString * const NSPrintHorizontallyCentered; 
AirKit_EXPORT NSString * const NSPrintVerticallyCentered; 

@interface NSPrintInfo : NSObject <NSCopying> {
   NSMutableDictionary *_attributes;
}

+(NSPrintInfo *)sharedPrintInfo;

-initWithDictionary:(NSDictionary *)dictionary;

-(NSMutableDictionary *)dictionary;

-(NSPrinter *)printer;
-(NSString *)jobDisposition;

-(NSString *)paperName;
-(NSSize)paperSize;
-(NSPrintingOrientation)orientation;

-(NSPrintingPaginationMode)horizontalPagination;
-(NSPrintingPaginationMode)verticalPagination;

-(float)topMargin;
-(float)bottomMargin;
-(float)leftMargin;
-(float)rightMargin;

-(BOOL)isHorizontallyCentered;
-(BOOL)isVerticallyCentered;

-(NSString *)localizedPaperName;
-(NSRect)imageablePageBounds;

-(void)setPrinter:(NSPrinter *)printer;
-(void)setJobDisposition:(NSString *)value;

-(void)setPaperName:(NSString *)value;
-(void)setPaperSize:(NSSize)value;
-(void)setOrientation:(NSPrintingOrientation)value;

-(void)setHorizontalPagination:(NSPrintingPaginationMode)value;
-(void)setVerticalPagination:(NSPrintingPaginationMode)value;

-(void)setTopMargin:(float)value;
-(void)setBottomMargin:(float)value;
-(void)setLeftMargin:(float)value;
-(void)setRightMargin:(float)value;

-(void)setHorizontallyCentered:(BOOL)value;
-(void)setVerticallyCentered:(BOOL)value;

-(void)setUpPrintOperationDefaultValues;

@end
