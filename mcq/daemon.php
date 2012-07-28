<?php 
#component
 class component{
  public function add($name){
	}
	public function handle(){
	}
}
class menu extends component{
	private $children = array();
	private $name = NULL ;
	public function __construct($name){
		$this->name = $name;
	}
	public function add($obj){
		$this->children[] = $obj;
	}
	public function handle(){
		echo "menu". rand();;
		foreach($this->children as $child){
			$child->handle();
		}
	}
}
class leaf extends component{
	private $name = null;
	public function __construct($name){
		$this->name = $name;
	}
	public function handle(){
		echo $this->name . rand();
	}
}

echo microtime();

$allmenu = new menu('allmenu1');
$menu = new menu('menu1');
$menu = new menu('menu1');
$leaf = new leaf('leaf1');
$allmenu->add($menu);
$menu->add($leaf);
$menu->add($leaf);
$allmenu->handle();
