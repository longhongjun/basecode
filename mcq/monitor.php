<?php

include "conf.php";
class monitor{
	private $_process_list = array();
	private $_restart_list =  array();
	private $_zombie_limit = 300;
	private $_php_bin;
	private $_script_name;
	private $_uptime;
	public function __construct(){
		$this->check_self_proc();	
	}
	private function check_self_proc(){
	
	}

}
new monitor;
