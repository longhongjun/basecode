<?php
class ItemController extends CController{
	# http://hj4.weibo.com/demos/helloworld/index.php?r=item/create
	public function ActionCreate(){
		$model = new Item();var_dump($model);die;
		if(isset($_POST['Item'])){
			$model->attributes = $_POST['Item'];
			$model->image = CUploadedFile::getInstance($model, 'image');
			if ($model->save){
				$model->image->saveAs("/tmp/123");
			}
		}
	}
}