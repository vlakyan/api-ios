/*******************************************************************************

 Copyright (c) 2014, MapsWithMe GmbH
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ******************************************************************************/

#import <Foundation/Foundation.h>

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_7_0
  #error "maps.me supports iOS >= 7.0 only"
#endif

// Wrapper for a pin on a map
@interface MWMPin : NSObject
/// [required] pin latitude
@property (nonatomic) CGFloat lat;
/// [required] pin longitude
@property (nonatomic) CGFloat lon;
/// [optional] pin title
@property (nullable, copy, nonatomic) NSString * title;
/// [optional] passed back to the app when pin is clicked, OR, if it's a valid url,
/// it will be opened from MapsWithMe after selecting "More Details..." for the pin
@property (nullable, copy, nonatomic) NSString * idOrUrl;

- (nullable instancetype)initWithLat:(CGFloat)lat
                                 lon:(CGFloat)lon
                               title:(nullable NSString *)title
                             idOrUrl:(nullable NSString *)idOrUrl;

@end


// MapsWithMe API interface
@interface MWMApi : NSObject

/// returns YES if url is received from MapsWithMe and can be parsed
+ (BOOL)isMapsWithMeUrl:(nonnull NSURL *)url;
/// returns nil if user didn't select any pin and simply pressed "Back" button
+ (nullable MWMPin *)pinFromUrl:(nonnull NSURL *)url;
/// returns NO if MapsWithMe is not installed or outdated version doesn't support API calls
+ (BOOL)isApiSupported;
/// Simply opens MapsWithMe app
+ (BOOL)showMap;
/// Displays given point on a map, title and id are optional.
/// If id contains valid url, it will be opened from MapsWithMe after selecting "More Details..." for the pin
+ (BOOL)showLat:(CGFloat)lat lon:(CGFloat)lon title:(nullable NSString *)title idOrUrl:(nullable NSString *)idOrUrl;
/// The same as above but using pin wrapper
+ (BOOL)showPin:(nullable MWMPin *)pin;
/// Displays any number of pins
+ (BOOL)showPins:(nonnull NSArray<MWMPin *> *)pins;
//
+ (void)showMapsWithMeIsNotInstalledDialog;
/// Set value = YES if you want to open pin URL on balloon click, default value is NO
+ (void)setOpenUrlOnBalloonClick:(BOOL)value;

@end
