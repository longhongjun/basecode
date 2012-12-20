<?php
class DemoSubject implements SplSubject
{
	private $observers;
	private $value;
	public function __construct()
	{
		$this->observers=array();
	}
	public function attach(SplObserver $observer)
	{
		$this->observers[]=$observer;
	}
	public function detach(SplObserver $observer)
	{
		if($id=array_search($observer,$this->observers,true))
		{
			unset($this->observers[$id]);
		}
	}
	public function notify()
	{
		foreach($this->observers as $observer)
		{
			$observer->update($this);
		}
	}
	public function set_value($value)
	{
		$this->value=$value;
		$this->notify();
	}
	public function get_value()
	{
		return $this->value;
	}
}
class DemoObserver implements SplObserver
{
	private $lastnum;
	public function update(SplSubject $subject)
	{
		echo 123;
		$this->lastnum=$subject->get_value();
	}
	public function show()
	{
		echo $this->lastnum;
	}
}
$subject = new DemoSubject();
$observer = new DemoObserver();
$subject->attach($observer);
$subject->set_value(5);
$subject->set_value(9);
$observer->show();

die;
//FilterIterator 只能被用作基类，子类必须要实现其中的accept方法，accept方法必须为当项返回true or false
class great extends FilterIterator
{
	public $test;
	public $arr;
	public function __construct($arr,$value)
	{
		parent::__construct($arr);
		$this->test=$value;
	}
	public function accept()
	{
		return ($this->current()>$this->test);
	}
} // end class
$s=range(1,5);
$arr=new ArrayIterator($s);
$a=new great($arr,4);
print_r(iterator_to_array($a));

die;

/**
 AppendIterator使用起來就像DOM裏面的appendChild()是一樣的道理就是能把一個迭代器附加在另外一個迭代器的後面
 連接倆個迭代器
 */
$a1=range(0,3);
$a2=range(3,7);
$a1=new ArrayIterator($a1);
$a2=new ArrayIterator($a2);
$iterator=new AppendIterator();
$iterator->append($a1);
$iterator->append($a2);
foreach($iterator as $value)
{
    echo $value;
}

/**
 LimitIterator使用方法
 可以初步實現分頁等功能
 實際使用技巧有待發現
 */
$arr=range(0,10);
$arr=new ArrayIterator($arr);
$limit=new LimitIterator($arr,3,4);
foreach($limit as $v)
{
	echo $v;
}



die;
