//
//  RowTypeRule.swift
//  Example
//
//  Created by Slience on 2021/3/16.
//

import UIKit
 
protocol HomeRowTypeRule {
    var title: String { get }
    var controller: UIViewController { get }
}

protocol ConfigRowTypeRule {
    var title: String { get }
    var detailTile: String { get }
    
    func getFunction<T: UIViewController>(_ controller: T) -> ((IndexPath) -> Void)
}

protocol RowTypeRule {
    var title: String { get }
    var options: String { get }
    
    func getFunction<T: UIViewController>(_ controller: T) -> ((IndexPath) -> Void)
}

extension RowTypeRule {
    
    func getFunction<T: UIViewController>(_ controller: T) -> ((IndexPath) -> Void) {
        return { _ in  }
    }
}
