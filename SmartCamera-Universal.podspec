#
# Be sure to run `pod lib lint SmartCamera-Universal.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "SmartCamera-Universal"
  s.version          = "1.2.4"
  s.summary          = "SmartCamera for iOS"
  s.homepage         = "https://github.com/azhisoft/SmartCamera_iOS"
  s.license          = 'Apache License, Version 2.0'
  s.author           = { "azhisoft" => "azhisoft@163.com" }
  s.source           = { :git => "https://github.com/azhisoft/SmartCamera_iOS.git", :tag => "v#{s.version}" }

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  s.subspec "universal" do |ss1|
    ss1.vendored_framework = "releases/Library-Universal/SmartCamera.framework"
  end

  s.frameworks = ["UIKit", "Foundation"]

end
