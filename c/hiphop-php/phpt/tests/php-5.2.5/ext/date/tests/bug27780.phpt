--TEST--
Bug #27780 (strtotime(+1 xxx) returns a wrong date/time)
--FILE--
<?php
$timezones = array (
	"America/Chicago", "Europe/Amsterdam", "Asia/Jerusalem",
	"Asia/Singapore", "America/Sao_Paulo"
);

$timestrings = array (
	"2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +59 seconds",
	"2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +60 seconds",
	"2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +61 seconds",
	"2004-04-07 00:00:00 -21 days",
	"2004-04-07 00:00:00 11 days ago",
	"2004-04-07 00:00:00 -10 day +2 hours",
	"2004-04-07 00:00:00 -1 day",
	"2004-04-07 00:00:00",
	"2004-04-07 00:00:00 +1 hour",
	"2004-04-07 00:00:00 +2 hour",
	"2004-04-07 00:00:00 +1 day",
	"2004-04-07 00:00:00 1 day",
	"2004-04-07 00:00:00 +21 days",
);

foreach ($timezones as $timezone) {
///	putenv("TZ=$timezone");
	echo $timezone, "\n";

	foreach ($timestrings as $timestring) {
		$time = strtotime($timestring);

		echo $time, strftime(" [%Y-%m-%d %H:%M:%S %Z]", $time), " [$timestring]\n";
	}

	echo "\n";
}
?>
--EXPECT--
America/Chicago
1076824799 [2004-02-14 23:59:59 CST] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +59 seconds]
1076824800 [2004-02-15 00:00:00 CST] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +60 seconds]
1076824801 [2004-02-15 00:00:01 CST] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +61 seconds]
1079503200 [2004-03-17 00:00:00 CST] [2004-04-07 00:00:00 -21 days]
1080367200 [2004-03-27 00:00:00 CST] [2004-04-07 00:00:00 11 days ago]
1080460800 [2004-03-28 02:00:00 CST] [2004-04-07 00:00:00 -10 day +2 hours]
1081227600 [2004-04-06 00:00:00 CDT] [2004-04-07 00:00:00 -1 day]
1081314000 [2004-04-07 00:00:00 CDT] [2004-04-07 00:00:00]
1081317600 [2004-04-07 01:00:00 CDT] [2004-04-07 00:00:00 +1 hour]
1081321200 [2004-04-07 02:00:00 CDT] [2004-04-07 00:00:00 +2 hour]
1081400400 [2004-04-08 00:00:00 CDT] [2004-04-07 00:00:00 +1 day]
1081400400 [2004-04-08 00:00:00 CDT] [2004-04-07 00:00:00 1 day]
1083128400 [2004-04-28 00:00:00 CDT] [2004-04-07 00:00:00 +21 days]

Europe/Amsterdam
1076799599 [2004-02-14 23:59:59 CET] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +59 seconds]
1076799600 [2004-02-15 00:00:00 CET] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +60 seconds]
1076799601 [2004-02-15 00:00:01 CET] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +61 seconds]
1079478000 [2004-03-17 00:00:00 CET] [2004-04-07 00:00:00 -21 days]
1080342000 [2004-03-27 00:00:00 CET] [2004-04-07 00:00:00 11 days ago]
1080435600 [2004-03-28 03:00:00 CEST] [2004-04-07 00:00:00 -10 day +2 hours]
1081202400 [2004-04-06 00:00:00 CEST] [2004-04-07 00:00:00 -1 day]
1081288800 [2004-04-07 00:00:00 CEST] [2004-04-07 00:00:00]
1081292400 [2004-04-07 01:00:00 CEST] [2004-04-07 00:00:00 +1 hour]
1081296000 [2004-04-07 02:00:00 CEST] [2004-04-07 00:00:00 +2 hour]
1081375200 [2004-04-08 00:00:00 CEST] [2004-04-07 00:00:00 +1 day]
1081375200 [2004-04-08 00:00:00 CEST] [2004-04-07 00:00:00 1 day]
1083103200 [2004-04-28 00:00:00 CEST] [2004-04-07 00:00:00 +21 days]

Asia/Jerusalem
1076795999 [2004-02-14 23:59:59 IST] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +59 seconds]
1076796000 [2004-02-15 00:00:00 IST] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +60 seconds]
1076796001 [2004-02-15 00:00:01 IST] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +61 seconds]
1079474400 [2004-03-17 00:00:00 IST] [2004-04-07 00:00:00 -21 days]
1080338400 [2004-03-27 00:00:00 IST] [2004-04-07 00:00:00 11 days ago]
1080432000 [2004-03-28 02:00:00 IST] [2004-04-07 00:00:00 -10 day +2 hours]
1081202400 [2004-04-06 00:00:00 IST] [2004-04-07 00:00:00 -1 day]
1081288800 [2004-04-07 00:00:00 IST] [2004-04-07 00:00:00]
1081292400 [2004-04-07 02:00:00 IDT] [2004-04-07 00:00:00 +1 hour]
1081292400 [2004-04-07 02:00:00 IDT] [2004-04-07 00:00:00 +2 hour]
1081371600 [2004-04-08 00:00:00 IDT] [2004-04-07 00:00:00 +1 day]
1081371600 [2004-04-08 00:00:00 IDT] [2004-04-07 00:00:00 1 day]
1083099600 [2004-04-28 00:00:00 IDT] [2004-04-07 00:00:00 +21 days]

Asia/Singapore
1076774399 [2004-02-14 23:59:59 SGT] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +59 seconds]
1076774400 [2004-02-15 00:00:00 SGT] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +60 seconds]
1076774401 [2004-02-15 00:00:01 SGT] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +61 seconds]
1079452800 [2004-03-17 00:00:00 SGT] [2004-04-07 00:00:00 -21 days]
1080316800 [2004-03-27 00:00:00 SGT] [2004-04-07 00:00:00 11 days ago]
1080410400 [2004-03-28 02:00:00 SGT] [2004-04-07 00:00:00 -10 day +2 hours]
1081180800 [2004-04-06 00:00:00 SGT] [2004-04-07 00:00:00 -1 day]
1081267200 [2004-04-07 00:00:00 SGT] [2004-04-07 00:00:00]
1081270800 [2004-04-07 01:00:00 SGT] [2004-04-07 00:00:00 +1 hour]
1081274400 [2004-04-07 02:00:00 SGT] [2004-04-07 00:00:00 +2 hour]
1081353600 [2004-04-08 00:00:00 SGT] [2004-04-07 00:00:00 +1 day]
1081353600 [2004-04-08 00:00:00 SGT] [2004-04-07 00:00:00 1 day]
1083081600 [2004-04-28 00:00:00 SGT] [2004-04-07 00:00:00 +21 days]

America/Sao_Paulo
1076810399 [2004-02-14 23:59:59 BRST] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +59 seconds]
1076814000 [2004-02-15 00:00:00 BRT] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +60 seconds]
1076814001 [2004-02-15 00:00:01 BRT] [2004-04-07 00:00:00 -2 months +7 days +23 hours +59 minutes +61 seconds]
1079492400 [2004-03-17 00:00:00 BRT] [2004-04-07 00:00:00 -21 days]
1080356400 [2004-03-27 00:00:00 BRT] [2004-04-07 00:00:00 11 days ago]
1080450000 [2004-03-28 02:00:00 BRT] [2004-04-07 00:00:00 -10 day +2 hours]
1081220400 [2004-04-06 00:00:00 BRT] [2004-04-07 00:00:00 -1 day]
1081306800 [2004-04-07 00:00:00 BRT] [2004-04-07 00:00:00]
1081310400 [2004-04-07 01:00:00 BRT] [2004-04-07 00:00:00 +1 hour]
1081314000 [2004-04-07 02:00:00 BRT] [2004-04-07 00:00:00 +2 hour]
1081393200 [2004-04-08 00:00:00 BRT] [2004-04-07 00:00:00 +1 day]
1081393200 [2004-04-08 00:00:00 BRT] [2004-04-07 00:00:00 1 day]
1083121200 [2004-04-28 00:00:00 BRT] [2004-04-07 00:00:00 +21 days]
