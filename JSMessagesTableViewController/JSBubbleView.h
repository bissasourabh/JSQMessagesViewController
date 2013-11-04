//
//  Created by Jesse Squires on 2/12/13.
//  Copyright (c) 2013 Hexed Bits. All rights reserved.
//
//  http://www.hexedbits.com
//
//
//  Originally based on work by Sam Soffes
//  https://github.com/soffes
//
//  SSMessagesViewController
//  https://github.com/soffes/ssmessagesviewcontroller
//
//
//  The MIT License
//  Copyright (c) 2013 Jesse Squires
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
//  associated documentation files (the "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
//  following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
//  LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
//  OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>

extern CGFloat const kJSAvatarSize;

typedef NS_ENUM(NSUInteger, JSBubbleMessageType) {
    JSBubbleMessageTypeIncoming,
    JSBubbleMessageTypeOutgoing
};


typedef NS_ENUM(NSUInteger, JSBubbleMessageStyle) {
    JSBubbleMessageStyleDefault,
    JSBubbleMessageStyleSquare,
    JSBubbleMessageStyleDefaultGreen
};


@interface JSBubbleView : UIView

@property (assign, nonatomic) JSBubbleMessageType type;
@property (assign, nonatomic) JSBubbleMessageStyle style;
@property (weak, nonatomic) UIImageView *bubbleImageView;

#pragma mark - Initialization

- (instancetype)initWithFrame:(CGRect)rect
                   bubbleType:(JSBubbleMessageType)bubleType
                  bubbleStyle:(JSBubbleMessageStyle)bubbleStyle;

#pragma mark - Setters

- (void)setText:(NSString *)newText;

#pragma mark - Getters

- (NSString *)text;

#pragma mark - Drawing

- (CGRect)bubbleFrame;
- (UIImage *)bubbleImage;
- (UIImage *)bubbleImageHighlighted;

#pragma mark - Bubble view

+ (UIImage *)bubbleImageForType:(JSBubbleMessageType)aType
                          style:(JSBubbleMessageStyle)aStyle;

+ (UIFont *)font;

+ (CGSize)textSizeForText:(NSString *)txt;
+ (CGSize)bubbleSizeForText:(NSString *)txt;
+ (CGFloat)cellHeightForText:(NSString *)txt;

+ (int)maxCharactersPerLine;
+ (int)numberOfLinesForMessage:(NSString *)txt;

@end