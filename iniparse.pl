#!/usr/local/bin/perl

use Data::Dumper;

$delim = "=";

$inputfile = $ARGV[0];

if (!open(INFILE, $inputfile)) {
	print "can not open file ".$inputfile."\n";
	exit(0);
}

$current_section = "";

while (<INFILE>) {
	chomp;
	s/\;.*//;
	s/^\s*$//;
	if ($_ eq "") {
		next;
	}
	s/\s+$//;

	if (/^\[(.+)\]/) {
		if ($current_section ne "") {
			print "</section>\n";
		}
		print "<section name=\"".$1."\">\n";
		$current_section = $1;
	} elsif (/^(.*)${delim}(.*)$/) {
		if ($current_section eq "") {
			print "<section name=\"default\">\n";
			$current_section = "default";
		}
		print "\t<param key=\"".$1."\" value=\"".$2."\">\n";
	}
}
if ($current_section ne "") {
	print "</section>\n";
}

close(INFILE);
