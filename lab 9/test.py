import urllib.request
import time
from plyer import notification

# intranet urls
impartus_url = "http://172.16.3.20/ilc/#/home"
sophos_login_url = "http://172.16.0.30:8090/"
wait_time = 120  # in sec


def test_connection(host=impartus_url):
    try:
        urllib.request.urlopen(host)
        return True
    except:
        return False


while True:
    if test_connection():
        print("Lan back Up")
        notification.notify(
            title="Lan Back",
            message="lan back up",
            app_icon="download.jpeg",
            timeout=10,
        )
    else:
        print("Lan still down")
        notification.notify(
            title="Lan Back",
            message="not yet",
            app_icon="download.jpeg",
            timeout=10,
        )
    time.sleep(wait_time)
