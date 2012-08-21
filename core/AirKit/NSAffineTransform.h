#import <Foundation/NSAffineTransform.h>

@class NSBezierPath;

@interface NSAffineTransform(AirKit)

-(void)concat;
-(void)set;

-(NSBezierPath *)transformBezierPath:(NSBezierPath *)bezierPath;

@end
