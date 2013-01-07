<?php

$form = $this->beginWidget(
		'CActiveWidget',
		array(
				'id'=>'upload-form',
				'enableAjaxValidation'=>false,
				'htmlOptions'=>array('enctype'=>'multipart/form-data'),
				)
		);
echo $form->labelEx($model, 'image');
echo $form->fileField($model, 'image');
echo $form->error($model, 'image');

$this->endWidget();