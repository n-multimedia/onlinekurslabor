Site:           <?php print $base_url; ?> 
Severity:       <?php print $log['severity_desc']; ?> (<?php print $log['severity']; ?>)
Timestamp:      <?php print $log['datetime']; ?> 
Type:           <?php print $log['type']; ?> 
IP Address:     <?php print $log['ip']; ?> 
Request URI:    <?php print $log['request_uri']; ?> 
Referrer URI:   <?php print $log['referer']; ?> 
User:           <?php print $log['name']; ?> (<?php print $log['uid']; ?>)
Link:           <?php print $log['link']; ?> 
Message:

<?php print $log['message']; ?> 


<?php foreach ($log['debug_info'] as $name => $value): ?>
<?php print $name; ?> => <?php print_r($value); ?> 

<?php endforeach; ?>
