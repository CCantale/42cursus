<?php
define( 'DB_NAME', 'db1' );
define( 'DB_USER', 'user' );
define( 'DB_PASSWORD', 'pwd' );
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );
define( 'WP_ALLOW_REPAIR', true );

define('AUTH_KEY',         '#F{Mf2*zw)dSsWuFoUqJ-Z*s+q(-p7.GkqXbcwNUGjO$)2Rb@*T1k)ED:m>;|(ux');
define('SECURE_AUTH_KEY',  'N* -n%:!,!uw%yo(,P4 |8+~N-O01F02nVY<<INp&D)YZ?UiQKq!;L![SDjs^+|a');
define('LOGGED_IN_KEY',    '1ri#BL|+SP^-M+rMM{t0VFqMBYga!2koihI{tdmgos|Bq7^n{)4(1(4j0CM7UiyA');
define('NONCE_KEY',        '+;46h#$$)|PA9QU=!<hU0U]/e^F-:&XNYfBhotpbt|3kj|Eg,:?wQ-oN{QqsxhPL');
define('AUTH_SALT',        ';Q(;:,w<M<_3i~*v4{I&4;g_+ (zvuR_ {<UH{ wt8|)WtTPa#UcZ<Hma#z [:SY');
define('SECURE_AUTH_SALT', '@~-i6:_NzmvL:Y@yq5OE br+V|PFL]f#|;|rT+;$=Kl0oY38Wm-<P#*&rTA>k8&p');
define('LOGGED_IN_SALT',   'dr+XwIB2%8&,<V-{Xr0Xi<04 +3-~.U-<-;oL( fsi2+!LNoFNO`_kBHJ @N!sp:');
define('NONCE_SALT',       'NA|^+VE n^y#khyq#ag-D$GWktl9xNjcpIu)d&c+8b?Dn8&z+xL?z9Pxv:CtdhKF');
define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_REDIS_PORT', 6379 );     


define('WP_CACHE', true);
$table_prefix = 'wp_';
define( 'WP_DEBUG', true );

if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}
require_once ABSPATH . 'wp-settings.php';
?>
