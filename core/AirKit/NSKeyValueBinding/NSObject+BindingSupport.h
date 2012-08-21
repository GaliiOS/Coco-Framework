/* Copyright (c) 2007 Johannes Fortmann

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
#import <Foundation/NSObject.h>
#import <AirKit/AirKitExport.h>

@class NSDictionary,NSArray,NSString;

@interface NSObject (BindingSupport)
-(void)bind:(id)binding toObject:(id)destination withKeyPath:(NSString*)keyPath options:(NSDictionary*)options;
-(NSDictionary *)infoForBinding:(id)binding;
-(void)unbind:(id)binding;
+(void)exposeBinding:(id)binding;
@end

@interface NSObject (InternalBindingSupport)
// returns a dictionary with the default options for the specified binding
// the dictionaries are stored on a per-class basis in defaultBindingOptions.plist
// the binding parameter is currently ignored
-(NSDictionary *)_defaultBindingOptionsForBinding:(NSString *)binding;

// return the class of a suitable binder for the respective binding
+(Class)_binderClassForBinding:(id)binding;

// return the respective binder or nil if unbound
-(id)_binderForBinding:(id)binding;

// return a suitable binder for the binding. if create is NO, only returns a binder
// if the binding is actually in use
-(id)_binderForBinding:(id)binding create:(BOOL)create;

// return a key path suitable for KVO to replace the generic binding name
// e.g. "value" -> "color" on NSColorWell
-(id)_replacementKeyPathForBinding:(id)binding;

// returns all binders used by the object
-(NSArray*)_allUsedBinders;

// unbinds all bindings used; should be called in -dealloc
-(void)_unbindAllBindings;

// the currently set value is a placeholder and should be displayed accordingly
-(id)_setCurrentValueIsPlaceholder:(BOOL)isPlaceholder;
@end

@interface NSObject (NSEditor)
-(BOOL)commitEditing;
-(void)discardEditing;
@end

@interface NSObject (NSEditorRegistration)
-(void)objectDidBeginEditing:editor;
-(void)objectDidEndEditing:editor;
@end

AirKit_EXPORT NSString * const NSObservedObjectKey;
AirKit_EXPORT NSString * const NSObservedKeyPathKey;
AirKit_EXPORT NSString * const NSOptionsKey;

// Binding option keys
AirKit_EXPORT NSString * const NSNullPlaceholderBindingOption;
AirKit_EXPORT NSString * const NSNoSelectionPlaceholderBindingOption;
AirKit_EXPORT NSString * const NSMultipleValuesPlaceholderBindingOption;
AirKit_EXPORT NSString * const NSCreatesSortDescriptorBindingOption;
AirKit_EXPORT NSString * const NSRaisesForNotApplicableKeysBindingOption;
AirKit_EXPORT NSString * const NSAllowsEditingMultipleValuesSelectionBindingOption;
AirKit_EXPORT NSString * const NSValueTransformerNameBindingOption;
AirKit_EXPORT NSString * const NSValueTransformerBindingOption;
AirKit_EXPORT NSString * const NSConditionallySetsEnabledBindingOption;
AirKit_EXPORT NSString * const NSConditionallySetsEditableBindingOption;
AirKit_EXPORT NSString * const NSContinuouslyUpdatesValueBindingOption;
AirKit_EXPORT NSString * const NSDisplayPatternBindingOption;

enum {
	kNSBindingDebugLogLevel1 = 1,
	kNSBindingDebugLogLevel2,
	kNSBindingDebugLogLevel3
};

AirKit_EXPORT void NSDetermineBindingDebugLoggingLevel();

AirKit_EXPORT int NSBindingDebugLogLevel; // Defaults to 0 = no logging

#define NSBindingDebugLog(level, format, args...) NSDetermineBindingDebugLoggingLevel(); if (NSBindingDebugLogLevel >= level ) NSLog(@"%d: %s line: %d | %@", level, __PRETTY_FUNCTION__, __LINE__, [NSString stringWithFormat: format, ## args])

