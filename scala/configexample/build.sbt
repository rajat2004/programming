name := "configexample"

version := "0.1"

scalaVersion := "2.13.2"

//libraryDependencies += "org.apache.spark" %% "spark-streaming" % "2.4.5"
libraryDependencies ++= Seq(
  "com.typesafe" % "config" % "1.4.0"
)