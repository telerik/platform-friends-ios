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

@property (nonatomic, strong) Class contentType;
@property (strong, nonatomic) NSPredicate* predicate;
@property (strong, nonatomic) NSArray* sortDescriptors;
@property (nonatomic) NSInteger fetchLimit;
@property (nonatomic) NSInteger fetchOffset;
@property (nonatomic,strong) NSArray* subsetOfFields;
@property (nonatomic) BOOL fieldsInclusionMode;
@property (nonatomic) id expand;
+ (EVFetchRequest*)fetchRequestWithKindOfClass:(Class)class;
- (id)initRequestWithKindOfClass:(Class)class;
@end
