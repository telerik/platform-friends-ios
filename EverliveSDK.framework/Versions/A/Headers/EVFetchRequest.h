//
//  EVFetchRequest.h
//  EverliveSDK
//
//  Created by Pavel Pavlov on 8/5/13.
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum _SubsetFieldsInclusionMode{
    IncludeSubsetFields = YES,
    ExcludeSubsetFields = NO
} SubsetFieldsInclusionMode;

@interface EVFetchRequest : NSObject

// EVFile != "Files" its been set by +description overload. In this way developer can have their own class name.
@property (nonatomic, strong) Class contentType;
@property (strong, nonatomic) NSPredicate* predicate;
@property (strong, nonatomic) NSArray* sortDescriptors;
@property (nonatomic) NSInteger fetchLimit;
@property (nonatomic) NSInteger fetchOffset;
@property (nonatomic,strong) NSArray* subsetOfFields;
@property (nonatomic) BOOL fieldsInclusionMode;

//BOOL test = [self isKindOfClass:[SomeClass class]];
+ (EVFetchRequest*)fetchRequestWithKindOfClass:(Class)class;
- (id)initRequestWithKindOfClass:(Class)class;
@end
