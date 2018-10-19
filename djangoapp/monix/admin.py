from django.contrib import admin

from .models import Member

class MemberInline(admin.TabularInline):
    model = Member
    extra = 3
admin.site.register(Member)

