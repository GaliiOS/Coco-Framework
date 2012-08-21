#import <AirKit/NSPrintPanel.h>
#import <AirKit/NSPrintOperation.h>
#import <AirKit/NSPrintInfo.h>
#import <AirKit/NSPanel.h>
#import <AirKit/NSDisplay.h>
#import <Foundation/NSDictionary.h>

@implementation NSPrintPanel

+(NSPrintPanel *)printPanel {
   return [[[self alloc] init] autorelease];
}

-(int)runModal {
   int result;
   
   [self updateFromPrintInfo];
   result=[[NSDisplay currentDisplay] runModalPrintPanelWithPrintInfoDictionary:_attributes];
   if(result==NSOKButton)
    [self finalWritePrintInfo];
    
   return result;
}

-(void)updateFromPrintInfo {
   NSDictionary *source=[[[NSPrintOperation currentOperation] printInfo] dictionary];
   
   [_attributes release];
   _attributes=[source mutableCopy];
}

-(void)finalWritePrintInfo {
   NSMutableDictionary *destination=[[[NSPrintOperation currentOperation] printInfo] dictionary];
   
   [destination addEntriesFromDictionary:_attributes];
}

@end
