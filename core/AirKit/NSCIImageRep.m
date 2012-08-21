#import <AirKit/NSCIImageRep.h>
#import <AirKit/NSRaise.h>
#import <AirKit/NSBitmapImageRep.h>

@implementation CIImage(CIImageRepAdditions)

-initWithBitmapImageRep:(NSBitmapImageRep *)bitmapImageRep {
   return [self initWithCGImage:[bitmapImageRep CGImage]];
}

@end
