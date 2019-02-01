<!-- Error Handling -->
[% IF whole.error %]
    <!-- Dispatch on Status -->
    <p>We encountered an error:</p>
    <ol>
        <li>[% whole.status %]</li>
        <li>[% whole.message %]</li>
    </ol>
[% END %]

[% IF whole.stage == "response" %]

    <p>We gave a response</p>

[% ELSIF whole.stage == "form" %]
    <h3>Receive outgoing request number [% whole.illrequest_id %].</h3>
    <form method="POST" action="/cgi-bin/koha/ill/ill-requests.pl?method=receive&illrequest_id=[% whole.illrequest_id %]">
    <fieldset class="rows">
        <legend>Request details</legend>
        <ol>
            <li class="illtitle"> <label class="illtitle">Title:</label>      [% whole.title %]</li>
            <li class="author">   <label class="author">Author:</label>       [% whole.author %]</li>
            <li class="lf_number"><label class="lf_number">LF number:</label> [% whole.lf_number %]</li>
        </ol>
    </fieldset>
    <fieldset class="rows">
        <legend>Receive</legend>
        <ol>
            <li class="ill_barcode">
                <label class="ill_barcode">Barcode:</label>
                <input type="text" name="ill_barcode" id="ill_barcode" />
            </li>
            <li class="title">
                <input name="stage" id="stage" value="receive" type="hidden"/>
                <input name="method" id="method" value="receive" type="hidden"/>
                <input name="illrequest_id" id="illrequest_id" value="[% whole.illrequest_id %]" type="hidden"/>
            </li>
        </ol>
    </fieldset>
    <fieldset class="rows">
        <legend>Message - email/print</legend>
        <ol>
            <li class="email_title">
                <label class="email_title">Title:</label>
                <input type="text" name="email_title" id="email_title" value="[% whole.email.title %]" />
           </li>
            <li class="email_content">
                <label class="email_content">Message:</label>
                <textarea name="email_content" id="email_content" rows="10" cols="50">[% whole.email.content %]</textarea>
           </li>
           <li class="send_email">
                <label class="send_email">Send message:</label>
                <input type="radio" name="send_email" value="0" checked> Nei
                <input type="radio" name="send_email" value="1"> Ja
           </li>
        </ol>
    </fieldset>
    <fieldset class="rows">
        <legend>Message - SMS</legend>
        <ol>
            <li class="sms_title">
                <label class="sms_title">Title:</label>
                <input type="text" name="sms_title" id="sms_title" value="[% whole.sms.title %]" />
           </li>
            <li class="sms_content">
                <label class="sms_content">Message:</label>
                <textarea name="sms_content" id="sms_content" rows="10" cols="50">[% whole.sms.content %]</textarea>
           </li>
           <li class="send_sms">
                <label class="send_sms">Send message:</label>
                <input type="radio" name="send_sms" value="0" checked> Nei
                <input type="radio" name="send_sms" value="1"> Ja
           </li>
        </ol>
    </fieldset>
    <input type="hidden" name="letter_code" id="letter_code" value="[% whole.letter_code %]" />
    <input type="submit" value="Receive">
    <a href="/cgi-bin/koha/ill/ill-requests.pl?method=illview&illrequest_id=[% whole.illrequest_id %]">Cancel</a>
    </form>
[% ELSE %]
    <p>We encountered an unexpected situation</p>
[% END %]