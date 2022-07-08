#!/usr/bin/perl -w

use strict;


open(FILE, "<dictionary") || die "File not found";
my @lines = <FILE>;
close(FILE);

my @newlines;

my @newlines_ipaddr;
my @newlines_string;
my @newlines_date;
my @newlines_integer;
my @newlines_other;
my @vendors;
my @attributes;
my $first_integer=1;
my $first_ipaddr=1;
my $first_string=1;
my $first_date=1;
my $i=0;
foreach(@lines) 
{
  my $j=0;
  my $str=$_;
  $str=~ tr/\t/ /;
  $str=~ s/ {2,}/ /g;
  $str=~ s/-/_/g;
  my @values=split(/ /,$str);
  my $line='';
  my $line2='';
  if ($values[0] eq 'VENDOR')
  {
    $values[1]=~ tr/\n//;
    $values[0]=~ tr/\n//;
    $values[2]=~ tr/\n//;
    $line="#define \t VENDOR_".uc($values[1])." \t".$values[2];
    $vendors[$i]={'id' => $values[2], 'name' => $values[1], 'define' => "VENDOR_".uc($values[1])};
    $i++;
  }
  elsif (($values[0] eq 'ATTRIBUTE') && defined($values[4]) && ($values[4] ne '') )
  {
    $attributes[$j]={id => $values[2], name => $values[1], define => "ATTRIBUTE_".uc($values[1]), type =>$values[3] };
    my $k=0;
    
    $values[4]=~ s/\s//g;
    $values[4]=~ tr/ //;
    $vendors[$k]{'name'}=~ s/\s//g;
    $vendors[$k]{'name'}=~ tr/ //;
    if($values[4] ne '')
    {
     while (($vendors[$k]{'name'} ne $values[4]) && defined($vendors[$k]{'name'}))
     {
       $k++;
     }
     $line="#define \t ATTRIBUTE_".uc($values[1])." \t".$values[2];  
    
     if ($values[3] eq 'integer')
     {
       if($first_integer eq 1)
       {
        $first_integer=0;
        $line2= "(id == ".$vendors[$k]{'define'} ." && type == ATTRIBUTE_".uc($values[1]).")\n";
       }
       else
       {
        $line2= "|| (id == ".$vendors[$k]{'define'} ." && type == ATTRIBUTE_".uc($values[1]).")\n";
       }
       push(@newlines_integer,$line2);
     }
     elsif($values[3] eq 'date')
     {
       if($first_date eq 1)
       {
        $first_date=0;
        $line2= "(id == ".$vendors[$k]{'define'} ." && type == ATTRIBUTE_".uc($values[1]).")\n";
       }
       else
       {
        $line2= "|| (id == ".$vendors[$k]{'define'} ." && type == ATTRIBUTE_".uc($values[1]).")\n";
       }
       push(@newlines_date,$line2);
     }
     elsif($values[3] eq 'string')
     {
       if($first_string eq 1)
       {
        $first_string=0;
        $line2= "(id == ".$vendors[$k]{'define'} ." && type == ATTRIBUTE_".uc($values[1]).")\n";
       }
       else
       {
        $line2= "|| (id == ".$vendors[$k]{'define'} ." && type == ATTRIBUTE_".uc($values[1]).")\n";
       
       }
      push(@newlines_string,$line2);
     }
     elsif($values[3] eq 'ipaddr')
     {
       if($first_ipaddr eq 1)
       {
        $first_ipaddr=0;
        $line2= "(id == ".$vendors[$k]{'define'} ." && type == ATTRIBUTE_".uc($values[1]).")\n";
       }
       else
       {
        $line2= "|| (id == ".$vendors[$k]{'define'} ." && type == ATTRIBUTE_".uc($values[1]).")\n";
       }
      push(@newlines_ipaddr,$line2);
     }
     else
     {
       $line2= "NOT SUPPORTED DATATYPE : $values[3] : id == ".$vendors[$k]{'define'} ."&& type == ATTRIBUTE_".uc($values[1])."\n";
       push(@newlines_other,$line2);
     }
    }
  
  }
  else
  {
    # other lines are added as comment
  }
  $line.="  \t//".$_;
  push(@newlines,$line);
}


open(FILE2, ">./vsa.h") || die "File could not be opened.";
print FILE2 qq|/* File was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
        |;
print FILE2 "#ifndef _VSA_H_  \n";
print FILE2 "#define _VSA_H_  \n";
print FILE2 @newlines;
print FILE2 "#endif  \n";
close(FILE2);

open(FILE3, ">./vsa_if_statements.txt") || die "File could not be opened.";
print FILE3 qq|/* File was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
        |;
print FILE3 qq|/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
|;
print FILE3 qq|if (
|;
print FILE3 @newlines_integer;
print FILE3 qq|)
{
 sprintf(buffer, "%d", vsa->intFromBuf());
 return 	string(buffer);
}
|;

print FILE3 qq|/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
|;
print FILE3 qq|else if (
|;
print FILE3 @newlines_date;
print FILE3 qq|)
{
 sprintf(buffer, "%d", vsa->intFromBuf());
 return 	string(buffer);
}
|;

print FILE3 qq|/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
|;
print FILE3 qq|else if (
|;
print FILE3 @newlines_string;
print FILE3 qq|)
{
 return vsa->stringFromBuf();
}
|;

print FILE3 qq|/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
|;
print FILE3 qq|else if (
|;
print FILE3 @newlines_ipaddr;
print FILE3 qq|)
{
 return vsa->ipFromBuf();
}|;
print FILE3 qq|
else
{
 cerr << "Vendor Specific Attribute (Id: " << vsa->getId() << " Type: " << vsa->getType() << " not implemented, treated as string.";
 return vsa->stringFromBuf();
}
|;
print FILE3 qq|/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
|;
print FILE3 @newlines_other;
close(FILE3);

exit(0);