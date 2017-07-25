//
//  ShelfViewController.h
//  Baker
//
//  ==========================================================================================
//
//  Copyright (c) 2010-2013, Davide Casali, Marco Colombo, Alessandro Morandi
//  Copyright (c) 2014, Andrew Krowczyk, Cédric Mériau, Pieter Claerhout
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this list of
//  conditions and the following disclaimer.
//  Redistributions in binary form must reproduce the above copyright notice, this list of
//  conditions and the following disclaimer in the documentation and/or other materials
//  provided with the distribution.
//  Neither the name of the Baker Framework nor the names of its contributors may be used to
//  endorse or promote products derived from this software without specific prior written
//  permission.
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>

#import "BKRIssue.h"
#import "BKRIssuesManager.h"
#import "BKRShelfStatus.h"
#import "BKRBakerAPI.h"
#import "BKRPurchasesManager.h"
#import "BKRCategoryFilterButton.h"
#import "BKRShelfViewLayout.h"
#import "BKRIssueCell.h"

@class BKRShelfHeaderView;

@interface BKRShelfViewController : UIViewController <UICollectionViewDataSource, UICollectionViewDelegate, UIActionSheetDelegate, UIWebViewDelegate, BKRCategoryFilterButtonDelegate, BKRIssueCellDelegate, BKRPurchasesManagerDelegate> {
    BKRBakerAPI *api;
    BKRIssuesManager *issuesManager;
    NSMutableArray *notRecognisedTransactions;
    UIPopoverController *infoPopover;
    BKRPurchasesManager *purchasesManager;
}

@property (nonatomic, copy) NSArray *issues;
@property (nonatomic, copy) NSArray *supportedOrientation;

@property (nonatomic, strong) BKRShelfStatus *shelfStatus;

@property (nonatomic, strong) IBOutlet UICollectionView *gridView;
@property (nonatomic, strong) IBOutlet BKRShelfViewLayout *layout;
@property (nonatomic, strong) CAGradientLayer *gradientLayer;
@property (nonatomic, strong) IBOutlet BKRShelfHeaderView *headerView;
@property (nonatomic, strong) IBOutlet UIButton *refreshButton;
@property (nonatomic, strong) IBOutlet UIButton *subscribeButton;
@property (strong, nonatomic) IBOutlet UIButton *infoButton;
@property (strong, nonatomic) IBOutlet BKRCategoryFilterButton *categoryButton;

@property (nonatomic, strong) UIActionSheet *subscriptionsActionSheet;
@property (nonatomic, strong) NSArray *subscriptionsActionSheetActions;
@property (nonatomic, strong) UIAlertView *blockingProgressView;

@property (nonatomic, copy) NSString *bookToBeProcessed;
@property (nonatomic, strong) BKRIssue *issueToBeRead;

- (IBAction)handleInfoButtonPressed:(id)sender;

#pragma mark - Init
- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)configureForNewsstand;
- (void)configureWithBooks:(NSArray*)currentBooks;

#pragma mark - Shelf data source
- (IBAction)handleRefresh:(id)sender;

#pragma mark - Navigation management
- (void)readIssue:(BKRIssue*)issue;
- (void)receiveBookProtocolNotification:(NSNotification*)notification;
- (void)handleBookToBeProcessed;
- (void)pushViewControllerWithIssue:(BKRIssue*)issue;

#pragma mark - Buttons management
- (void)setRefreshButtonEnabled:(BOOL)enabled;
- (void)setSubscribeButtonEnabled:(BOOL)enabled;
- (IBAction)handleSubscribeButtonPressed:(id)sender;

#pragma mark - Helper methods
- (int)getBannerHeight;

@end
