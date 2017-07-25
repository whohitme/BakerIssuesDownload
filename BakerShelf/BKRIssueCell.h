//
//  BKRIssueCell.h
//  Baker
//
//  ==========================================================================================
//
//  Copyright (c) 2010-2013, Davide Casali, Marco Colombo, Alessandro Morandi
//  Copyright (c) 2014, Andrew Krowczyk, Cédric Mériau, Pieter Claerhout
//  Copyright (c) 2015, Andrew Krowczyk, Cédric Mériau, Pieter Claerhout, Tobias Strebitzer
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

#import "BKRIssue.h"

@protocol BKRIssueCellDelegate;

@interface BKRIssueCell : UICollectionViewCell<BKRIssueDelegate>

@property (nonatomic, weak) IBOutlet id<BKRIssueCellDelegate> delegate;

@property (nonatomic, strong) IBOutlet UIButton *actionButton;
@property (nonatomic, strong) IBOutlet UIButton *archiveButton;
@property (nonatomic, strong) IBOutlet UIProgressView *progressBar;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *spinner;
@property (nonatomic, strong) IBOutlet UILabel *loadingLabel;

@property (nonatomic, strong) IBOutlet UIButton *issueCover;
@property (nonatomic, strong) IBOutlet UILabel *titleLabel;
@property (nonatomic, strong) IBOutlet UILabel *infoLabel;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *issueCoverRatioConstraint;

@property (nonatomic, strong) BKRIssue *issue;

#pragma mark - Issue management
- (IBAction)actionButtonPressed:(id)sender;
- (IBAction)archiveButtonPressed:(id)sender;

#pragma mark - View management
- (void)updateView;

@end

@protocol BKRIssueCellDelegate <NSObject>

- (void)issueCell:(BKRIssueCell *)cell requestsReadActionForIssue:(BKRIssue *)issue;
- (void)issueCell:(BKRIssueCell *)cell requestsPurchaseActionForIssue:(BKRIssue *)issue;
- (void)issueCell:(BKRIssueCell *)cell requestsDownloadActionForIssue:(BKRIssue *)issue;
- (void)issueCell:(BKRIssueCell *)cell requestsArchiveActionForIssue:(BKRIssue *)issue;

@end