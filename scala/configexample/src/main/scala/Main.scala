import com.typesafe.config.{Config, ConfigFactory}

object ReadConfigFile extends App {
  val config: Config = ConfigFactory.load("example.conf")

  val name = config.getString("app.name")
  val list = config.getList("app.list")
  val version = config.getInt("app.version")
  val subarray = config.getList("app.sub-array")
  println(s"name = $name")
  println(s"list = $list")
  list.forEach(println)
  println(s"version = $version")
  println(s"subarray = $subarray")
}