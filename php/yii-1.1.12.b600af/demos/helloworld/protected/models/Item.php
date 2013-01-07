<?php
class Item extends CActiveForm{
	public $image;
	public function rules(){
		return array(
				array('image', 'file', 'types'=>'jpg,png,jpeg,gif'),
				);
	}
	
	
}