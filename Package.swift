// swift-tools-version:5.3
import PackageDescription
let package = Package(
  name: "BanubaEffectPlayer",
  platforms: [
    .iOS(.v11)
  ],
  products: [
    .library(
      name: "BanubaEffectPlayer", 
      targets: ["BanubaEffectPlayer"])
  ],
  targets: [
    .binaryTarget(
      name: "BanubaEffectPlayer", 
      path: "BanubaEffectPlayer.xcframework")
  ])
