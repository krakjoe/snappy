snappy
======

Snappy is a fast compression algorythm from Google, it favours performance over ratios, and I love all that ...

http://code.google.com/p/snappy/

Most linux distros can install snappy using their package manager, use yum|apt-get install snappy-dev[el]

API
===

```php
<?php
/*
* Compress data using snappy compression
* @return string
*/
function snappy_compress($data);

/*
* Validates a compressed string
* @return boolean
*/
function snappy_validate($data);

/*
* Decompress data using snappy compression
* @return string
*/
function snappy_uncompress($data);
?>
```

That's all so far, stream wrappers to come ...
