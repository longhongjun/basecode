<?php
///putenv("TZ=US/Eastern");
if (date('T') == 'GMT') {
	putenv("TZ=EST5EDT4,M4.1.0,M10.5.0");
}
echo date("r\n", strtotime("Sep 04 16:39:45 2001"));
echo date("r\n", strtotime("Sep 04 2001 16:39:45"));	
?>
--EXPECT--
Tue, 04 Sep 2001 16:39:45 -0400
Tue, 04 Sep 2001 16:39:45 -0400
