<?php
class duck{
	public $fly_obj;
	public $qua_obj;
	public function __construct($fly_obj, $qua_obj){
		$this->fly_obj = $fly_obj;
		$this->qua_obj = $qua_obj;
	}
	public function get_name(){
		echo "default";
	}
	public function get_fly(){
		$this->fly_obj->get_fly();
	}
	public function get_qua(){
		$this->qua_obj->get_qua();
	}
}
class a_duck extends duck{
	public function __construct($fly_obj, $qua_obj){
		parent::__construct($fly_obj, $qua_obj);
	}
	public function get_name(){
		echo "a duck";
	}
}
class b_duck extends duck{
	public function get_name(){
		echo "b duck";
	}
}
interface fly{
	public function get_fly();
}
class a_fly implements  fly{
	public function get_fly(){
		echo "fly_with wing";
	}
}
class b_fly implements fly{
	public function get_fly(){
		echo "fly with with wing";
	}
}
interface qua{
	public function get_qua();
}
class a_qua implements  qua{
	public function get_qua(){
		echo "que wing";
	}
}
class b_qua implements qua{
	public function get_qua(){
		echo "qua with wing";
	}
}

$fly = new a_fly();
$qua = new a_qua();
$duck = new a_duck($fly, $qua);
$duck->get_fly();
$duck->get_qua();

/*
class StrategyContext {
	private$strategy = NULL;
	//bookList is not instantiated at construct time
	public function __construct($strategy_ind_id) {
		switch ($strategy_ind_id) {
			case"C":
				$this->strategy = new StrategyCaps();
				break;
			case"E":
				$this->strategy = new StrategyExclaim();
				break;
			case"S":
				$this->strategy = new StrategyStars();
				break;
		}
	}
	public function showBookTitle($book) {
		return$this->strategy->showTitle($book);
	}
}

interface StrategyInterface {
	public function showTitle($book_in);
}

class StrategyCaps implements StrategyInterface {
	public function showTitle($book_in) {
		$title = $book_in->getTitle();
		$this->titleCount++;
		return strtoupper ($title);
	}
}

class StrategyExclaim implements StrategyInterface {
	public function showTitle($book_in) {
		$title = $book_in->getTitle();
		$this->titleCount++;
		return Str_replace(' ','!',$title);
	}
}

class StrategyStars implements StrategyInterface {
	public function showTitle($book_in) {
		$title = $book_in->getTitle();
		$this->titleCount++;
		return Str_replace(' ','*',$title);
	}
}

class Book {
	private$author;
	private$title;
	function __construct($title_in, $author_in) {
		$this->author = $author_in;
		$this->title  = $title_in;
	}
	function getAuthor() {
		return$this->author;
	}
	function getTitle() {
		return$this->title;
	}
	function getAuthorAndTitle() {
		return$this->getTitle() . ' by ' . $this->getAuthor();
	}
}

writeln('BEGIN TESTING STRATEGY PATTERN');
writeln('');

$book = new Book('PHP for Cats','Larry Truett');

$strategyContextC = new StrategyContext('C');
$strategyContextE = new StrategyContext('E');
$strategyContextS = new StrategyContext('S');

writeln('test 1 - show name context C');
writeln($strategyContextC->showBookTitle($book));
writeln('');

writeln('test 2 - show name context E');
writeln($strategyContextE->showBookTitle($book));
writeln('');

writeln('test 3 - show name context S');
writeln($strategyContextS->showBookTitle($book));
writeln('');

writeln('END TESTING STRATEGY PATTERN');

function writeln($line_in) {
	echo$line_in."<br/>";
}

*/
