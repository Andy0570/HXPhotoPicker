//
//  HXPhotoTools.h
//  照片选择器
//
//  Created by 洪欣 on 17/2/8.
//  Copyright © 2017年 洪欣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>
#import "HXPhotoModel.h"
#import "HXAlbumModel.h"
#import "UIView+HXExtension.h"
#import "NSBundle+HXPhotoPicker.h"
#import "NSDate+HXExtension.h"
#import "UILabel+HXExtension.h"
#import "UIFont+HXExtension.h"
#import "UIImage+HXExtension.h"
#import "NSTimer+HXExtension.h"
#import "NSString+HXExtension.h"
#import <CoreLocation/CoreLocation.h>
#import "HXPhotoDefine.h"
#import "HXPhotoCommon.h"


@class HXPhotoManager;
@interface HXPhotoTools : NSObject 

+ (void)saveModelToCustomAlbumWithAlbumName:(NSString * _Nullable)albumName
                                 photoModel:(HXPhotoModel * _Nullable)photoModel
                                   location:(CLLocation * _Nullable)location
                                   complete:(void (^ _Nullable)(HXPhotoModel * _Nullable model, BOOL success))complete;

/**
 保存本地视频到系统相册和自定义相册

 @param albumName 自定义相册名称
 @param videoURL 本地视频地址
 */
+ (void)saveVideoToCustomAlbumWithName:(NSString * _Nullable)albumName
                              videoURL:(NSURL * _Nullable)videoURL;
+ (void)saveVideoToCustomAlbumWithName:(NSString * _Nullable)albumName
                              videoURL:(NSURL * _Nullable)videoURL
                              location:(CLLocation * _Nullable)location
                              complete:(void (^ _Nullable)(HXPhotoModel * _Nullable model, BOOL success))complete;

/**
 保存图片到系统相册和自定义相册

 @param albumName 自定义相册名称
 @param photo uiimage
 */
+ (void)savePhotoToCustomAlbumWithName:(NSString * _Nullable)albumName
                                 photo:(UIImage * _Nullable)photo;
+ (void)savePhotoToCustomAlbumWithName:(NSString * _Nullable)albumName
                                 photo:(UIImage * _Nullable)photo
                              location:(CLLocation * _Nullable)location
                              complete:(void (^ _Nullable)(HXPhotoModel * _Nullable model, BOOL success))complete;
/**
 获取定位信息 
 */
+ (CLGeocoder * _Nullable)getDateLocationDetailInformationWithModel:(HXPhotoDateModel * _Nullable)model
                                               completion:(void (^ _Nullable)(CLPlacemark * _Nullable placemark, HXPhotoDateModel * _Nullable model, NSError * _Nullable error))completion;

/**
 请求相册权限
 */
+ (void)requestAuthorization:(UIViewController * _Nullable)viewController
                     handler:(void (^ _Nullable)(PHAuthorizationStatus status))handler;

+ (PHAuthorizationStatus)authorizationStatus;

/**
 判断是否是HEIF格式的图片
 */
+ (BOOL)assetIsHEIF:(PHAsset * _Nullable)asset;

/**
 导出裁剪的视频

 @param asset 视频AVAsset
 @param timeRange 裁剪时间区域
 @param presetName 导出的视频质量
 @param success 成功
 @param failed 失败
 */
+ (void)exportEditVideoForAVAsset:(AVAsset * _Nullable)asset
                        timeRange:(CMTimeRange)timeRange
                       presetName:(NSString * _Nullable)presetName
                          success:(void (^ _Nullable)(NSURL * _Nullable videoURL))success
                           failed:(void (^ _Nullable)(NSError * _Nullable error))failed;

/**
 获取视频的时长
 */
+ (NSString * _Nullable)transformVideoTimeToString:(NSTimeInterval)duration;

/**
 获取数组里面图片的大小
 */
+ (void)fetchPhotosBytes:(NSArray * _Nullable)photos
              completion:(void (^ _Nullable)(NSString * _Nullable totalBytes))completion;
+ (NSString * _Nullable)getBytesFromDataLength:(NSUInteger)dataLength;

+ (BOOL)platform;
/**  iphone6, 6s, 7, 8  */
+ (BOOL)isIphone6;


/// 判断网络地址是否在本地存在
/// 如果文件夹不存在则会创建文件夹
/// @param videoURL 网络视频地址
+ (BOOL)fileExistsAtVideoURL:(NSURL * _Nullable)videoURL;
+ (BOOL)fileExistsAtImageURL:(NSURL * _Nullable)ImageURL;
+ (BOOL)fileExistsAtLivePhotoImageURL:(NSURL * _Nullable)ImageURL;
+ (BOOL)fileExistsAtLivePhotoVideoURL:(NSURL * _Nullable)videoURL;

/// 将网络视频地址转换成本地文件名
/// @param videoURL 网络视频地址
+ (NSString * _Nullable)getVideoURLFilePath:(NSURL * _Nullable)videoURL;
+ (NSString * _Nullable)getImageURLFilePath:(NSURL * _Nullable)imageURL;
+ (NSString * _Nullable)getLivePhotoImageURLFilePath:(NSURL * _Nullable)imageURL;
+ (NSString * _Nullable)getLivePhotoVideoURLFilePath:(NSURL * _Nullable)videoURL;

+ (void)writeToFileWithOriginJPGPath:(NSURL * _Nonnull)originJPGPath
                 TargetWriteFilePath:(NSURL * _Nonnull)finalJPGPath
                          completion:(void (^ _Nullable)(BOOL success))completion;

+ (void)writeToFileWithOriginMovPath:(NSURL * _Nonnull)originMovPath
                 TargetWriteFilePath:(NSURL * _Nonnull)finalMovPath
                              header:(void (^ _Nullable)(AVAssetWriter * _Nullable writer, AVAssetReader * _Nullable videoReader, AVAssetReader * _Nullable audioReader))header
                          completion:(void (^ _Nullable)(BOOL success))completion;



#pragma mark - < 获取本地文件大小 >

/// 获取所有缓存的大小
+ (long long)getAllLocalFileSize;

/// 获取缓存在本地所有的HXPhotoModel的大小
+ (long long)getAllLocalModelsFileSize;

/// 获取生成LivePhoto缓存在本地的图片视频大小
+ (long long)getLivePhotoAssetFileSize;

/// 获取下载网络视频缓存的大小
+ (long long)getNetWorkVideoFileSize;

/// 删除HXPhotoPicker所有文件
+ (void)deleteAllLocalFile;

/// 删除本地HXPhotoModel缓存文件
+ (void)deleteAllLocalModelsFile;

/// 删除生成LivePhoto相关的缓存文件
+ (void)deleteLivePhotoCachesFile;

/// 删除下载的网络视频缓存文件
+ (void)deleteNetWorkVideoFile;
@end