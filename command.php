<?php
interface command{
	public function execute();
}
class a_comand implements command{
	public $receive;
	public function __construct($receive){
		$this->receive = $receive;
	}
	public function execute(){
		$this->receive->action();
	}
}
class receive{
	public $list;
	public function __construct($list){
		$this->list = $list;
	}
	public function action(){
		echo 'action';
	}
}
class invoke{
	public $list;
	public function __construct($list){
		$this->list = $list;
	}
	public function action(){
		$this->list->execute();
		
	}
}
$client = new receive('myname');
$command = new a_comand($client);
$invoke = new invoke($command);
$invoke->action();

