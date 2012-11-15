<?php
public class gumbalmachine{
  public $soldOutState;
	public $noQuarterState;
	public $hasQuarterState;
	public $soldState;

	public $state = $soldOutState;

	public $count = 0;

	public gumballmachine($number){
		$this->soldOutState = new SoldOutState();
		$this->noQuarterState = new  NoQuarterState();
		$this->hasQuarterState = new HasQuarterState();
		$this->soldState = new SoldState();
		$this->count = $number;
		if($number > 0){
			$this->state = $this->noQuarterState;
		}
	}
	public function insertQuarter(){
		$this->state->insertQuarter();
	}
	public function ejectQuarter(){
		$this->state->ejectQuarter();
	}
	public function turnCrank(){
		$this->state->turnCrank();
		$this->state->dispense();
	}
	public function setState($state){
		$this->state = $state;
	}
	public function releaseBall(){
		print ("a gumball comes rolling out the slot");
		if($this->count != 0){
			$this->count = $this->count -1;
		}
	}
	public function getNoQuarterState(){
		return $this->noQuarterState;
	}
}

interface State{
public function inertQuarter()
public function ejectQuarter()
public function turnCrank()
public function dispense()
}
public class NoQuarterState implements State{
public $gumballMachine;
public function NoQuarterState($gumballMachine){
	$this->gumballMachine = $gumballMachine;
}
public function insertQuater(){
	print("you insert a quarter");
	$this->gumballMachine->setState($this->gumballMachine->getHasQuarterState());
}
function ejectQuarter(){
	print("you havent inerted a quarter");
}
function turnCrank(){
	print("you turned ,but theres no quarter");
}
function dispense(){
	print("you need to pay first");
}
}

public class HasQuarterState implements State{
	public $gumballMachine;
	function HasQuarterState($gumballMachine){
		$this->gumballMachine = $gumballMachine;
	}

}
