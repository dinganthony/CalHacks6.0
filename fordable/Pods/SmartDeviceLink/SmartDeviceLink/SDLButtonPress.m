//
//  SDLButtonPress.m
//

#import "SDLButtonPress.h"
#import "SDLRPCParameterNames.h"
#import "SDLRPCFunctionNames.h"
#import "NSMutableDictionary+Store.h"

NS_ASSUME_NONNULL_BEGIN

@implementation SDLButtonPress

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
- (instancetype)init {
    if (self = [super initWithName:SDLRPCFunctionNameButtonPress]) {
    }
    return self;
}
#pragma clang diagnostic pop

- (instancetype)initWithButtonName:(SDLButtonName) buttonName moduleType:(SDLModuleType) moduleType {
    self = [self init];
    if (!self) {
        return nil;
    }

    self.buttonName = buttonName;
    self.moduleType = moduleType;

    return self;
}

- (void)setModuleType:(SDLModuleType)moduleType {
    [self.parameters sdl_setObject:moduleType forName:SDLRPCParameterNameModuleType];
}

- (SDLModuleType)moduleType {
    NSError *error = nil;
    return [self.parameters sdl_enumForName:SDLRPCParameterNameModuleType error:&error];
}

- (void)setButtonName:(SDLButtonName)buttonName {
    [self.parameters sdl_setObject:buttonName forName:SDLRPCParameterNameButtonName];
}

- (SDLButtonName)buttonName {
    NSError *error = nil;
    return [self.parameters sdl_enumForName:SDLRPCParameterNameButtonName error:&error];
}

- (void)setButtonPressMode:(SDLButtonPressMode)buttonPressMode {
    [self.parameters sdl_setObject:buttonPressMode forName:SDLRPCParameterNameButtonPressMode];
}

- (SDLButtonPressMode)buttonPressMode {
    NSError *error = nil;
    return [self.parameters sdl_enumForName:SDLRPCParameterNameButtonPressMode error:&error];
}

@end
NS_ASSUME_NONNULL_END
