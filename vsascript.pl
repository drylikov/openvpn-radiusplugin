#!/usr/bin/perl -w

use strict;


#	Attribute		Code
#-------------------------------------------
#  	username 		101			
#  	commonname 		102	
#	framedip 		103	
#	callingstationid 	104		
#	untrustedport 		105
#	framedroutes 		106		
#	vsabuf 			107


my $action='';
my $reykeying='';
my $buflen='';
my $attribnumber='';
my $len='';
my $callingstationid='';
my $untrustedport='';
my $username='';
my $commonname='';
my $framedip='';
my @framedroutes='';
my $pipe='';
my @attributes;
my $i=0;
my $j=0;


$pipe = $ARGV[0];

open(FIFO, "< $pipe") || print "fifo: $!\n";
my $l;

read (FIFO,$l,4); 
$action=unpack('N1',$l);
#print "VSAScript: Action: $action\n";

read (FIFO,$l,4); 
$reykeying=unpack('N1',$l);
#print "VSAScript: Rekeying: $action\n";

read (FIFO,$l,4); 
$buflen=unpack('N1',$l);
#print "VSAScript: buflen: $buflen\n";
$buflen=$buflen-12;
while($buflen > 0)
{
	read (FIFO,$l,4); 
	$attribnumber=unpack('N1',$l);
	#print "VSAScript: Attribute Number : $attribnumber\n";
	
	read (FIFO,$l,4); 
	$len=unpack('N1',$l);
	#print "VSAScript: Attribute Length : $len\n";
	
	
	$buflen=$buflen-8;
	if($attribnumber eq 101) 
	{
		read (FIFO,$l,$len);
		#print "VSAScript: Attribute Value : $l\n";
		$buflen=$buflen-$len;
		$username = $l;
	} 
	elsif($attribnumber eq 102)
	{
		read (FIFO,$l,$len);
		#print "VSAScript: Attribute Value : $l\n";
		$buflen=$buflen-$len;
		$commonname = $l;
	} 
	elsif($attribnumber eq 103)
	{
		read (FIFO,$l,$len);
		#print "VSAScript: Attribute Value : $l\n";
		$buflen=$buflen-$len;
		$framedip = $l;
	} 
	elsif($attribnumber eq 104)
	{
		read (FIFO,$l,$len);
		#print "VSAScript: Attribute Value : $l\n";
		$buflen=$buflen-$len;
		$callingstationid = $l;
	} 
	elsif($attribnumber eq 105)
	{
		read (FIFO,$l,$len);
		#print "VSAScript: Attribute Value : $l\n";
		$buflen=$buflen-$len;
		$untrustedport = $l;
	} 
	elsif($attribnumber eq 106)
	{
		read (FIFO,$l,$len);
		#print "VSAScript: Attribute Value : $l\n";
		$buflen=$buflen-$len;
		$framedroutes[$i] = $l;
		$i++;
	} 

	elsif($attribnumber eq 107)
	{
	  while($len>0)
	  {
	  print "VSAScript: Vendor specific attribute\n"; 
	  my $vendor_id;
	  my $vendor_number;
	  my $vendor_len;
	  read (FIFO,$l,4); 
	  $vendor_id=unpack('N1',$l);
	  #print "VSAScript: Vendor ID : $vendor_id\n";

	  read (FIFO,$l,1); 
	  $vendor_number=unpack('C',$l);
	  #print "VSAScript: Vendor Number : $vendor_number\n";

	  read (FIFO,$l,1); 
	  $vendor_len=unpack('C1',$l)-2;
	  #print "VSAScript: Vendor Value length : $vendor_len\n";
	  
	  read (FIFO,$l,$vendor_len); 
		
 	  #decoding for integer values	
	  if( 
 		($vendor_id eq 529 && $vendor_number eq 197) #vendor specific attribute : Ascend-Data-Rate
             or ($vendor_id eq 529 && $vendor_number eq 255) #vendor specific attribute : Ascend-Xmit-Rate
   	  )
	  {
		$l=unpack('N1',$l);
		$attributes[$j]{'id'}=$vendor_id;
		$attributes[$j]{'number'}=$vendor_number;
		$attributes[$j]{'value'}=$l;
		#print "VSAScript: Vendor Value: $l\n";
          }
          else # decoding for sting values
	  {
	    	$attributes[$j]{'id'}=$vendor_id;
		$attributes[$j]{'number'}=$vendor_number;
		$attributes[$j]{'value'}=$l;
		#print "VSAScript: Vendor Value: $l\n";
          }
	 
	  
	  $buflen=$buflen-6-$vendor_len;
	  $len=$len-6-$vendor_len;
	  $len=$len-1;
	  $buflen=$buflen-1;
	  $j++;
	  }
	}
	else
	{
		read (FIFO,$l,$len);
		#print "VSAScript: Undefined Attribute Value : $l\n";
		$buflen=$buflen-$len;
	}
}
close(FIFO);
print "\n---------------VSAScript----------------------\n";
if ($action eq 0) { print "\nAction: Authentication";}
elsif ($action eq 1) { print "\nAction: Client connect";}
elsif ($action eq 2) { print "\nAction: Client disconnect";}
else { print "\nAction: undefined!";}

if ($reykeying eq 0) { print "\nReykeying: No";}
elsif ($reykeying eq 1) { print "\nReykeying: Yes";}
else { print "\nReykeying: undefined!";}

print "\nUsername: $username";
print "\nCommonname: $commonname";
print "\nCallingstationid: $callingstationid";
print "\nUntrustedport: $untrustedport";
print "\nFramedIP: $framedip";
while($i>0)
{
	$i--;
	print "\nFramedRoute: $framedroutes[$i]";
}



while($j>0)
{
 $j--;
 print "\nVSA attribute: ";
 print "\nId ($j): ".$attributes[$j]{'id'};
 print "\nNumber ($j): ".$attributes[$j]{'number'};
 print "\nValue ($j): ".$attributes[$j]{'value'};
 
}
print "\n---------------VSAScript----------------------\n";
exit(0);


