/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/Foundation.h>
#import <AirKit/AirKitExport.h>

AirKit_EXPORT NSString * const NSColorPboardType;
AirKit_EXPORT NSString * const NSFileContentsPboardType;
AirKit_EXPORT NSString * const NSFilenamesPboardType;
AirKit_EXPORT NSString * const NSFontPboardType;
AirKit_EXPORT NSString * const NSPDFPboardType;
AirKit_EXPORT NSString * const NSPICTPboardType;
AirKit_EXPORT NSString * const NSPostScriptPboardType;
AirKit_EXPORT NSString * const NSRTFDPboardType;
AirKit_EXPORT NSString * const NSRTFPboardType;
AirKit_EXPORT NSString * const NSRulerPboardType;
AirKit_EXPORT NSString * const NSStringPboardType;
AirKit_EXPORT NSString * const NSTabularTextPboardType;
AirKit_EXPORT NSString * const NSTIFFPboardType;
AirKit_EXPORT NSString * const NSURLPboardType;

AirKit_EXPORT NSString * const NSDragPboard;
AirKit_EXPORT NSString * const NSFindPboard;
AirKit_EXPORT NSString * const NSFontPboard;
AirKit_EXPORT NSString * const NSGeneralPboard;
AirKit_EXPORT NSString * const NSRulerPboard;

@interface NSPasteboard : NSObject

+(NSPasteboard *)generalPasteboard;
+(NSPasteboard *)pasteboardWithName:(NSString *)name;

-(int)changeCount;

-(NSArray *)types;
-(NSString *)availableTypeFromArray:(NSArray *)types;

-(NSData *)dataForType:(NSString *)type;
-(NSString *)stringForType:(NSString *)type;
-propertyListForType:(NSString *)type;

-(int)declareTypes:(NSArray *)types owner:owner;

-(BOOL)setData:(NSData *)data forType:(NSString *)type;
-(BOOL)setString:(NSString *)string forType:(NSString *)type;
-(BOOL)setPropertyList:plist forType:(NSString *)type;

@end

@interface NSObject(NSPasteboard)
-(void)pasteboard:(NSPasteboard *)sender provideDataForType:(NSString *)type;
-(void)pasteboardChangedOwner:(NSPasteboard *)sender;
@end
