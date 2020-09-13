#!/usr/bin/perl
use strict;
use warnings;

my $string=<>;

my %contents;
sub filearr{
	my $filename=$_[0];
	my $fh;
	open($fh,"<",$filename);
	return (<$fh>);
}
@{$contents{"i"}}=filearr("ingredients.txt");
@{$contents{"m"}}=filearr("methods1.txt");
@{$contents{"M"}}=filearr("methods2.txt");

my $streams=0;

while($string =~ /([imM])([0-9]*) /g){
	print "\n","|" x $streams,"\n";
	if($1eq"i"){
		$streams++;
		print "|"x($streams-1);
	}elsif($1eq"M"){
		$streams--;
		print "|"x($streams-1),"V";
	}else{
		print "|"x($streams-1);
	}
	chomp $contents{$1}[$2];
	print $contents{$1}[$2],' ';
}

print "\n";
