//
//     ____    _                        __     _      _____
//    / ___\  /_\     /\/\    /\ /\    /__\   /_\     \_   \
//    \ \    //_\\   /    \  / / \ \  / \//  //_\\     / /\/
//  /\_\ \  /  _  \ / /\/\ \ \ \_/ / / _  \ /  _  \ /\/ /_
//  \____/  \_/ \_/ \/    \/  \___/  \/ \_/ \_/ \_/ \____/
//
//	Copyright Samurai development team and other contributors
//
//	http://www.samurai-framework.com
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//

#import "Samurai_Core.h"
#import "Samurai_Event.h"
#import "Samurai_UIConfig.h"

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

#import "Samurai_Resource.h"
#import "Samurai_Tree.h"

#pragma mark -

@class SamuraiDomNode;
@class SamuraiStyleSheet;
@class SamuraiRenderStoreNode;
@class SamuraiRenderStoreScope;
@class SamuraiRenderObject;

@interface SamuraiDocument : SamuraiResource

@prop_strong( NSString *,				href );
@prop_strong( NSString *,				type );
@prop_strong( NSString *,				media );

@prop_strong( NSString *,				rootTag );
@prop_strong( NSString *,				headTag );
@prop_strong( NSString *,				bodyTag );

@prop_strong( SamuraiDomNode *,			domTree );
@prop_strong( SamuraiStyleSheet *,		styleTree );
@prop_strong( SamuraiRenderObject *,	renderTree );

@prop_strong( NSMutableArray *,			externalImports );
@prop_strong( NSMutableArray *,			externalScripts );
@prop_strong( NSMutableArray *,			externalStylesheets );

+ (SamuraiDocument *)document;
+ (SamuraiDocument *)document:(SamuraiDomNode *)domNode;

- (SamuraiDocument *)childDocument;
- (SamuraiDocument *)childDocument:(SamuraiDomNode *)domNode;

- (SamuraiDomNode *)getRoot;
- (SamuraiDomNode *)getHead;
- (SamuraiDomNode *)getBody;

- (NSString *)computeTitle;

- (BOOL)reflow;

@end

#endif	// #if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)
