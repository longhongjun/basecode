<?php
class observer{
	public $list;
	
	public function set_list($obj){
		$this->list[] = $obj;
	}
	public function notice(){
		foreach($this->list as $v){
			$v->update_message();
		}
	}
	public function fuck(){
		$this->notice();
	}
}
interface board{
	public function update_message();
}
class a_board implements board{
	public function update_message(){
		echo "im a board";
	}
}
class b_board implements board{
	public function update_message(){
		echo "im b board";
	}
}
$a_board = new a_board();
$b_board = new b_board();
$observer = new observer();
$observer->set_list($a_board);
$observer->set_list($b_board);
$observer->fuck();
