<?php
interface target{
	function action_one();
	function action_two();
}

class adaptee{
	function action_one(){
		echo 1231;
	}
	function action_two(){
		echo 'two1';
	}
}
class adapter extends adaptee implements target{
	function action_one(){
		$obj = new adaptee();
		$obj->action_one();
	}
	function action_two(){
		$obj = new adaptee();
		$obj->action_two();
	}
}

class apapter_two implements target{
	public $list;
	public function __construct($obj){
		$this->list = $obj;
	}
	function action_one(){
		$this->list->action_one();
	}
	function action_two(){
		$this->list->action_two();
	}
}
$ad = new adapter();
$ad->action_one();
$ad->action_two();


$adaptee = new adaptee();
$adapter_two = new apapter_two($adaptee);
$adapter_two->action_one();
$adapter_two->action_two();
