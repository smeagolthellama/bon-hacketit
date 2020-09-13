#!/usr/bin/env perl
use Mojolicious::Lite;

get '/:string' => sub{
	my $self=shift;
	my $string=$self->stash('string');

	my $ren="<pre>";


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
		$ren.= "\n"."|" x $streams."\n";
		if($1eq"i"){
			$streams++;
			$ren.= "|"x($streams-1);
		}elsif($1eq"M"){
			$streams--;
			$ren.= "|"x($streams-1)."V";
		}else{
			$ren.= "|"x($streams-1);
		}
		chomp $contents{$1}[$2];
		$ren.= $contents{$1}[$2].' ';
	}

	$ren.= "\n</pre>";
	$self->render(text => $ren);
};

app->start;
__DATA__

@@ index.html.ep
% layout 'default';
% title 'Welcome';
Welcome to the Mojolicious real-time web framework!

@@ layouts/default.html.ep
<!DOCTYPE html>
<html>
  <head><title><%= title %></title></head>
  <body><%= content %></body>
</html>
